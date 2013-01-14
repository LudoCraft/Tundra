/** For conditions of distribution and use, see copyright notice in LICENSE

    InfiniteWorld.js - A demo/testbed scene for profiling bottlenecks when dealing with a large world.  */

// !ref: SceneBlockOnlyTerrainFlat.txml
// !ref: SceneBlockOnlyTerrain.txml
// !ref: SceneBlockOneNpc.txml
// !ref: SceneBlockMultipleNpcs.txml
// !ref: WaypointBot.txml
// !ref: FireEaterBot.txml

function OnScriptDestroyed()
{
    if (framework.IsExiting())
        return;
    console.UnregisterCommand("setImEnabled");
    console.UnregisterCommand("setPhysicsMotorEnabled");
    Stop();
}

function ParseBool(str)
{
    str = str.trim().toLowerCase();
    return (str == "true" || str == "yes" || str == "1" || str == "y" || str == "on") ? true : false;
}

function SetInterestManagementEnabled(params)
{
    syncmanager.interesetManagementEnabled = ParseBool(params[0]);
    Log("interestManagementEnabled " + syncmanager.interesetManagementEnabled);
}

var usePhysicsMotor = true;

function SetPhysicsMotorEnabled(params)
{
    usePhysicsMotor = ParseBool(params[0]);
    Log("usePhysicsMotor " + usePhysicsMotor);
}

// Logging shortcuts
function Log(msg) { console.LogInfo(msg); }
function LogW(msg) { console.LogWarning(msg); }
function LogE(msg) { console.LogError(msg); }
function LogD(msg) { console.LogDebug(msg); }

// Entry point for the script.
if (server.IsRunning())
{
    console.RegisterCommand("setImEnabled", "Sets interest management enabled or disabled").Invoked.connect(SetInterestManagementEnabled);
    console.RegisterCommand("setPhysicsMotorEnabled", "Sets usage of PhysicsMotor enabled or disabled").Invoked.connect(SetPhysicsMotorEnabled);

    // cNumRows and cNumCols must be uneven and >= 3: 3,5,7,9,...
    const cNumRows = cNumCols = 3;

    // Start point of the scene block matrix.
    const cStartPos = new float3(0, 0, 0);
    // NOTE: cNumPatches configurable only if .ntf is also re-authored.
    const cNumPatches = 8;
    const cBlockWidth = 16 * cNumPatches - 1;
    const cBlockHeight = 128;

    // Init the scene block matrix
    var sceneBlocks = new Array(cNumRows);
    for(var i = 0; i < cNumRows; ++i)
        sceneBlocks[i] = new Array(cNumCols);

    var userEntity = null;
    var previousBlock = null;
    var currentBlock = null;

    scene.physics.Updated.connect(ServerPhysicsUpdate);
//    if (!framework.IsHeadless())
//        frame.Updated.connect(AnimationUpdate);

    Start();
}
/*
else // Client simply updates animation, no other logic
{
    frame.Updated.connect(AnimationUpdate);
}
*/
    
// Structure representing one scene block in the NxN scene block matrix.
function SceneBlock(name, row, col, pos)
{
    this.name = name;
    this.row = row;
    this.col = col;
    this.pos = pos;
    this.entities = [];
    this.bots = [];
    this.aabb = new AABB(pos, new float3(pos.x + cBlockWidth, cBlockHeight, pos.z + cBlockWidth));
}

SceneBlock.prototype.toString = function()
{
    return this.name;
}

function Start()
{
    server.UserConnected.connect(HandleUserConnected);
    server.UserDisconnected.connect(HandleUserDisconnected);

    var users = server.AuthenticatedUsers();
    if (users.length > 0) // User already in, handle immediately
        HandleUserConnected(users[0].id, users[0]);

    frame.Updated.connect(Update)
}

function Stop()
{
    if (server.IsRunning())
    {
        for(var i = 0; i < cNumRows; ++i)
            for(var j = 0; j < cNumCols; ++j)
                RemoveSceneBlockAt(i, j/*,false*/);
        sceneBlocks = null;
    }
}

function HandleUserConnected(id, user)
{
    // TODO
//    if (sceneBlocks[0][0] == null)
//        CreateWorld();
    userEntity = scene.EntityByName("Avatar" + id);
    if (userEntity)
    {
        var userStartPos;
        // TODO: if known user, restore last known position for the user
        // else set to center of the scene
        var pos = new float3(cStartPos);
        for(var i = 0; i < cNumRows; ++i)
            for(var j = 0; j < cNumCols; ++j)
            {
                var block = InstantiateSceneBlock(pos, i, j);
                sceneBlocks[i][j] = block;

                if (block == CenterBlock())
                    userStartPos = new float3(pos);

                if (j == cNumCols-1) // Reached end of the row, proceed to next
                {
                    pos.x = cStartPos.x;
                    pos.z += cBlockWidth; // backwards +z
                }
                else // Proceed with the row.
                {
                    pos.x += cBlockWidth; // right +x
                }
            }

        // Position user in the middle of the middle block, add some height so that we don't end up under the terrain.
        userStartPos.x += cBlockWidth/2;
        userStartPos.y += 40;
        userStartPos.z += cBlockWidth/2;
        userEntity.placeable.SetPosition(userStartPos);
        userEntity.placeable.SetOrientation(Quat.FromEulerZYX(0,0,0));

        DebugDumpSceneBlocks();
    }
}

function HandleUserDisconnected()
{
    userEntity = null;
    // TODO: save user's last known pos
    // TODO: freeze scene if no users
}

// Finds the scene block at specified world position
function SceneBlockAt(pos)
{
    for(var i = 0; i < sceneBlocks.length; ++i)
        for(var j = 0; j < sceneBlocks[i].length; ++j)
            if (sceneBlocks[i][j] != null && sceneBlocks[i][j].aabb.Contains(pos))
                return sceneBlocks[i][j];
    return null;
}

function InstantiateSceneBlock(pos, rowIdx, colIdx)
{
    // Flat terrain
    var sceneBlockFile = asset.GetAsset("SceneBlockOnlyTerrainFlat.txml").DiskSource();
    // Terrain
    //var sceneBlockFile = asset.GetAsset("SceneBlockOnlyTerrain.txml").DiskSource();
    // Terrain + 1 FireEater:
    //var sceneBlockFile = asset.GetAsset("SceneBlockOneNpc.txml").DiskSource();
    // Terrain + 63 FireEaters:
    //var sceneBlockFile = asset.GetAsset("SceneBlockMultipleNpcs.txml").DiskSource();
    var entities = scene.LoadSceneXML(sceneBlockFile, false, false, 0);
    if (entities.length == 0)
    {
        LogE("InstantiateSceneBlock: Failed to instantiate " + sceneBlockFile);
        return;
    }

    // Set up terrain
    var t = entities[0].terrain.nodeTransformation;
    t.pos = pos;
    entities[0].terrain.nodeTransformation = t;
    var blockName = rowIdx.toString() + "," + colIdx.toString()
    entities[0].name = "Terrain" + blockName;

    // TODO aabb copied from SceneBlock ctor
    var aabb = new AABB(pos, new float3(pos.x + cBlockWidth, cBlockHeight, pos.z + cBlockWidth));
//    var botPrefab = asset.GetAsset("FireEaterBot.txml").DiskSource();
    var botPrefab = asset.GetAsset("WaypointBot.txml").DiskSource();
    const numBots = 24;
    var bots = [];
    for(i = 0; i < numBots; ++i)
    {
        var bot = scene.LoadSceneXML(botPrefab, false, false, 0)[0];
        var randomPos = aabb.PointInside(Math.random(), 0.01, Math.random());
        bot.placeable.SetPosition(randomPos);
        InitWaypoints(bot);
        bots.push(bot);
    }

    // Set up FireEaters
    /*
    if (entities.length > 1)
    {
        for(i = 1; i < entities.length; ++i)
        {
            var fireEaterPos = new float3(pos);
            fireEaterPos.x += cBlockWidth/2;
            //fireEaterPos.y += 40;
            fireEaterPos.y = entities[0].terrain.GetPoint(pos.x, pos.z) + 1;
            Log(fireEaterPos);
            fireEaterPos.z += cBlockWidth/2;
            entities[1].placeable.SetPosition(fireEaterPos);
        }
    }
    */

    var newBlock = new SceneBlock(blockName, rowIdx, colIdx, pos);
    //newBlock.entities = entities;
    newBlock.entities = entities.concat(bots);
    newBlock.bots = bots;

    Log("Scene block " + newBlock + " instantiated at " + entities[0].terrain.nodeTransformation.pos);

    return newBlock;
}

function RemoveSceneBlocks(blocks)
{
    for(var i = 0; i < blocks.length; ++i)
        RemoveSceneBlock(blocks[i]);
}

function RemoveSceneBlockAt(row, col/*, saveState*/)
{
    RemoveSceneBlock(sceneBlocks[row][col]/*, saveState*/);
}

function RemoveSceneBlock(block/*, saveState*/)
{
    if (block)
    {
        Log("Removing scene block " + block.name);
        // TODO
    //  if (saveState)
    //      scene.SaveSceneXML(block.name + ".txml", false, false);
        for(var i = 0; i < block.entities.length; ++i)
            try
            {
                scene.RemoveEntity(block.entities[i].id);
            }
            catch(e)
            {
                LogW("RemoveSceneBlock: " + e);
            }
    }
    else
        LogW("RemoveSceneBlock called with null block.");

    block  = null;
}

function MoveBlock(oldRow, oldCol, newRow, newCol)
{
    sceneBlocks[oldRow][oldCol] = sceneBlocks[newRow][newCol];
}

function DebugDumpSceneBlocks()
{
    var str = "";
    for(var i = 0; i < sceneBlocks.length; ++i)
        for(var j = 0; j < sceneBlocks[i].length; ++j)
        {
            str += "[" + sceneBlocks[i][j].name + "]";
            if (j == cNumCols-1 && i < cNumRows-1)
                str += "\n";
            else
                str += " ";
        }
    Log(str);
}

// Shortcuts
function CenterBlock() { return sceneBlocks[(cNumRows-1)/2][(cNumCols-1)/2]; }
function TopRightBlock() { return sceneBlocks[0][cNumCols-1]; }
function TopLeftBlock() { return sceneBlocks[0][0]; }
function BottomLeftBlock() { return sceneBlocks[cNumRows-1][0]; }
function BottomRightBlock() { return sceneBlocks[cNumRows-1][cNumCols-1]; }
function BottomCenterBlock() { return sceneBlocks[cNumRows-1][(cNumCols-1)/2]; }
function CenterRightBlock() { return sceneBlocks[(cNumRows-1)/2][cNumCols-1]; }
function TopCenterBlock() { return sceneBlocks[0][(cNumCols-1)/2]; }
function CenterLeftBlock() { return sceneBlocks[(cNumRows-1)/2][0]; }

var timer = 0;
var checkInterval = 2; // in seconds
var drawDebug = false;

function Update(frameTime)
{
    if (drawDebug)
        for(var i in sceneBlocks)
            for(var j in sceneBlocks[i])
                scene.ogre.DebugDrawAABB(sceneBlocks[i][j].aabb, 1, 0, 0);

    if (!userEntity)
        return;

    timer += frameTime;
    if (timer < checkInterval)
        return;
    timer = 0;

    currentBlock = SceneBlockAt(userEntity.placeable.transform.pos);
    if (!currentBlock) // Should happen only if scene matrix in malformed state
    {
        LogE("Update: could not find where the user at!");
        return;
    }

    if (currentBlock != previousBlock && previousBlock != null)
    {
        var dumpState = true;

        if (dumpState)
        {
            Log("WAS:")
            DebugDumpSceneBlocks();
        }

        var oldBlocks = [], newBlocks = [];
        var deltaRow = currentBlock.row - previousBlock.row;
        var deltaCol = currentBlock.col - previousBlock.col;
        Log("Prev " + previousBlock + " Curr " + currentBlock);
        Log("deltaRow " + deltaRow + " deltaCol " + deltaCol);
        if (deltaRow == 0 && deltaCol > 0) // Moving right
        {
            // Append new column, remove leftmost column (00, 10, 20)
            Log("MOVING RIGHT");

            var pos = new float3(TopRightBlock().aabb.minPoint);
            pos.x += deltaCol * cBlockWidth;

            // Instantiate new blocks
            for(var i = 0, row = currentBlock.row-1; i < cNumRows; ++i, ++row)
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol)); // +1
                pos.z += cBlockWidth; // backwards +z
            }

            // Gather blocks to be removed.
            for(var i = 0; i < newBlocks.length; ++i)
                oldBlocks.push(sceneBlocks[i][0]);

            // Re-arrange the scene block matrix.
            // Move columns left, excluding the last column
            for(var col = 0; col < cNumCols-1; ++col)
                for(var i = 0; i < cNumRows; ++i)
                    sceneBlocks[i][col] = sceneBlocks[i][col+1];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var i = 0; i < newBlocks.length; ++i)
                sceneBlocks[i][cNumCols-1] = newBlocks[i];
        }
        else if (deltaRow == 0 && deltaCol < 0) // Moving left
        {
            // Preprend new column, remove rightmost column(2)
            Log("MOVING LEFT");

            var pos = new float3(TopLeftBlock().aabb.minPoint);
            pos.x += deltaCol * cBlockWidth;

            // Instantiate new blocks
            for(var i = 0, row = currentBlock.row-1; i < cNumRows; ++i, ++row)
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol)); //-1
                pos.z += cBlockWidth;
            }
            // Gather blocks to be removed.
            for(var i = 0; i < newBlocks.length; ++i)
                oldBlocks.push(sceneBlocks[i][cNumCols-1]);

            // Re-arrange the scene block matrix.
            // Move columns right, excluding the first column
            for(var col = cNumCols-1; col > 0; --col)
                for(var i = 0; i < cNumRows; ++i)
                    sceneBlocks[i][col] = sceneBlocks[i][col-1];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var i = 0; i < newBlocks.length; ++i)
                sceneBlocks[i][0] = newBlocks[i];
        }
        else if (deltaRow > 0 && deltaCol == 0) // Moving backwards/"down"
        {
            // Append new row, remove top row 0
            Log("MOVING DOWN");

            var pos = new float3(BottomLeftBlock().aabb.minPoint);
            pos.z += deltaRow * cBlockWidth;

            // Instantiate new blocks
            for(var j = 0, col = BottomLeftBlock().col; j < cNumCols; ++j, ++col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, col)); // +1
                pos.x += cBlockWidth;
            }

            // Gather blocks to be removed (first row)
            for(var j = 0; j < newBlocks.length; ++j)
                oldBlocks.push(sceneBlocks[0][j]);

            // Re-arrange the scene block matrix.
            // Row 1 becomes row 0, row 2 becomes row 1 etc.
            for(var row = 0; row < cNumRows-1; ++row)
                for(var j = 0; j < cNumCols; ++j)
                    sceneBlocks[row][j] = sceneBlocks[row+1][j];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var j = 0; j < newBlocks.length; ++j)
                sceneBlocks[cNumRows-1][j] = newBlocks[j];
        }
        else if (deltaRow < 0  && deltaCol == 0) // Moving forward/"up"
        {
            // Prepend new column, remove bottom row
            Log("MOVING UP");

            var pos = new float3(TopLeftBlock().aabb.minPoint);
            pos.z += deltaRow * cBlockWidth;

            // Instantiate new blocks
            for(var j = 0, col = TopLeftBlock().col; j < cNumCols; ++j, ++col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, col)); // -1
                pos.x += cBlockWidth;
            }

            // Gather blocks to be removed (bottom row)
            for(var j = 0; j < newBlocks.length; ++j)
                oldBlocks.push(sceneBlocks[cNumRows-1][j]);

            // Re-arrange the scene block matrix.
            // Row 1 becomes row 2, row 0 becomes row 1 etc.
            for(var row = cNumRows-1; row > 0; --row)
                for(var j = 0; j < cNumCols; ++j)
                    sceneBlocks[row][j] = sceneBlocks[row-1][j];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var j = 0; j < newBlocks.length; ++j)
                sceneBlocks[0][j] = newBlocks[j];
        }
        else if (deltaCol > 0 && deltaRow > 0)
        {
            // Append new column and new row, remove leftmost column and topmost row.
            Log("MOVING RIGHT AND DOWN");
            var pos = new float3(CenterRightBlock().aabb.minPoint);
            pos.x += deltaCol * cBlockWidth;

            // Instantiate new blocks
            for(var i = 0, row = currentBlock.row-1; i < cNumRows; ++i, ++row)
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol)); // +1
                pos.z += cBlockWidth; // backwards +z
            }
            // One step back to both dirs, instantiate row from right to left
            pos.z -= cBlockWidth;
            pos.x -= cBlockWidth;
            for(var j = 0, col = currentBlock.col; j < cNumCols-1; ++j, --col) // bottom right is already instantiated
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, col)); // +1
                pos.x -= cBlockWidth;
            }

            // Gather blocks to be removed.
            for(var i = 0; i < cNumRows; ++i) // Leftmost column
                oldBlocks.push(sceneBlocks[i][0]);
            for(var j = 1; j < cNumCols; ++j) // Top row, skip top-left block j=0, as it's already included
                oldBlocks.push(sceneBlocks[0][j]);

            // Re-arrange the scene block matrix: move each element left and up
            for(var i = 0; i < cNumRows-1; ++i)
                for(var j = 0; j < cNumCols-1; ++j)
                    sceneBlocks[i][j] = sceneBlocks[i+1][j+1];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            var idx = 0;
            for(var i = 0; idx < cNumRows; ++idx, ++i)
                sceneBlocks[i][cNumCols-1] = newBlocks[idx];
            for(var j = cNumCols-1-1; idx < newBlocks.length; ++idx, --j)
                sceneBlocks[cNumRows-1][j] = newBlocks[idx];
        }
        else if (deltaCol > 0 && deltaRow < 0)
        {
            // Append new column and new row, remove leftmost column and bottom row
            Log("MOVING RIGHT AND UP");
            var pos = new float3(TopCenterBlock().aabb.minPoint);
            //pos.x += deltaCol * cBlockWidth;
            pos.z += deltaRow * cBlockWidth;

            for(var j = 0, col = currentBlock.col-1; j < cNumCols; ++j, ++col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, col));
                pos.x += cBlockWidth;
            }
            pos.x -= cBlockWidth;
            for(var i = 0, row = currentBlock.row; i < cNumRows-1; ++i, ++row)  // cNumRows-1, the new top right is already instantiated
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol)); // +1
                pos.z += cBlockWidth; // backwards +z
            }

            // Gather blocks to be removed.
            for(var i = 0; i < cNumRows; ++i) // leftmost column
                oldBlocks.push(sceneBlocks[i][0]);
            for(var j = 1; j < cNumCols; ++j) // bottom row, skip first as already handled
                oldBlocks.push(sceneBlocks[cNumRows-1][j]);

            // Re-arrange the scene block matrix: move each element left and down
            for(var i = cNumRows-1; i > 0; --i)
                for(var j = 0; j < cNumCols-1; ++j)
                    sceneBlocks[i][j] = sceneBlocks[i-1][j+1];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            var idx = 0;
            for(var j = 0; idx < cNumCols-1; ++idx, ++j)
                sceneBlocks[0][j] = newBlocks[idx];
            for(var i = 0; idx < newBlocks.length; ++idx, ++i)
                sceneBlocks[i][cNumCols-1] = newBlocks[idx];
        }
        else if (deltaCol < 0 && deltaRow > 0)
        {
            // Preprend new column, remove rightmost column
            // Append new row, remove top row
            Log("MOVING LEFT AND DOWN");

            var pos = new float3(BottomCenterBlock().aabb.minPoint);
            pos.z += cBlockWidth;
            
            // instantiate new bottom row from right to left
            for(var j = 0, col = currentBlock.col+1; j < cNumCols; ++j, --col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, BottomCenterBlock().row+deltaRow, col));
                pos.x -= cBlockWidth;
            }
            pos.x += cBlockWidth;
            pos.z -= cBlockWidth;
            // instantiate new leftmost column from down to up
            for(var i = 0, row = currentBlock.row; i < cNumRows-1; ++i, --row) // cNumCols-1 as bottom left already instantiated
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col-1));
                pos.z -= cBlockWidth;
            }

            // Gather blocks to be removed.
            for(var j = 0; j < cNumRows; ++j) // top row
                oldBlocks.push(sceneBlocks[0][j]);
            for(var i = 1; i < cNumCols; ++i)  // rightmost column
                oldBlocks.push(sceneBlocks[i][cNumCols-1]);

            // Re-arrange the scene block matrix: Move each element right and up
            for(var i = 0; i < cNumRows-1; ++i)
                for(var j = 0; j < cNumCols-1; ++j)
                    sceneBlocks[i][j+1] = sceneBlocks[i+1][j];

            RemoveSceneBlocks(oldBlocks);

            // Insert new blocks.
            var idx = 0;
            for(var j = cNumCols-1; j >= 0; --j)
                sceneBlocks[cNumRows-1][j] = newBlocks[idx++];
            for(var i = cNumRows-1-1; i >= 0; --i)
                sceneBlocks[i][0] = newBlocks[idx++];
        }
        else if (deltaCol < 0 && deltaRow < 0)
        {
            // Preprend new column, remove rightmost column and bottom row
            Log("MOVING LEFT AND UP");
            
            var pos = new float3(CenterLeftBlock().aabb.minPoint);
            pos.x += deltaCol * cBlockWidth;

            // Add new leftmost column
            for(var i = 0, row = CenterLeftBlock().row; i < cNumRows; ++i, --row)
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol));
                pos.z -= cBlockWidth;
            }
            // Add new top row, skip top left, already instantiated
            pos.z += cBlockWidth;
            pos.x += cBlockWidth;
            for(var j = 0, col = currentBlock.col+deltaCol+1; j < cNumCols-1; ++j, ++col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, col));
                pos.x += cBlockWidth;
            }

            // Gather blocks to be removed
            for(var j = 0; j < cNumCols; ++j) // bottom row
                oldBlocks.push(sceneBlocks[cNumRows-1][j]);
            for(var i = 0; i < cNumRows-1; ++i) // rightmost column
                oldBlocks.push(sceneBlocks[i][cNumCols-1]);

            // Re-arrange the scene block matrix: move each right and down
            for(var i = cNumRows-1; i > 0; --i)
                for(var j = 0; j < cNumCols-1; ++j)
                    sceneBlocks[i][j+1] = sceneBlocks[i-1][j];

            RemoveSceneBlocks(oldBlocks);

            // Insert new blocks.
            var idx = 0;
            for(var i = cNumRows-1; i >= 0; --i)
                sceneBlocks[i][0] = newBlocks[idx++];
            for(var j = 1; j < cNumCols; ++j)
                sceneBlocks[0][j] = newBlocks[idx++];
        }
        else
        {
            LogE("SHOULD NOT END UP HERE EVER!");
        }

        if (dumpState)
        {
            Log("IS:")
            DebugDumpSceneBlocks();
        }
    }

    previousBlock = currentBlock;
}

// Bot functionality begins here

function InitWaypoints(/*Entity*/ bot)
{
    // Set in TXML already
//    if (usePhysicsMotor)
//        bot.physicsmotor.dampingForce = new float3(3.0, 0.0, 3.0);
    bot.waypoints = [new float3(10, 0, 10), new float3(-10, 0, 10), new float3(-10, 0, -10), new float3(10, 0, -10)];
    bot.currentWaypoint = 0;
    for(var i = 0; i < bot.waypoints.length; ++i)
    {
        bot.waypoints[i] = bot.waypoints[i].Mul(Math.random());
        bot.waypoints[i] = bot.waypoints[i].Add(bot.placeable.WorldPosition());
    }
}

var physicsTimer = 0;
var physicsCheckInterval = 0.5; // in seconds

function ServerPhysicsUpdate(frameTime)
{
    if (!currentBlock)
        return;

    physicsTimer += frameTime;
    if (physicsTimer < physicsCheckInterval)
        return;
    physicsTimer = 0;

    profiler.BeginBlock("InfiniteWorld_ServerPhysicsUpdate");

    for(var i = 0; i < cNumRows; ++i)
        for(var j = 0; j < cNumCols; ++j)
        {
            var block = sceneBlocks[i][j];
            for(var k = 0; k < block.bots.length; ++k)
            {
                var bot = block.bots[k];

                var targetPos = bot.waypoints[bot.currentWaypoint];
                TurnToSmooth(bot, ComputeTargetHeading(bot, targetPos), 0.05);

                // Move the bot
                if (usePhysicsMotor)
                    bot.physicsmotor.absoluteMoveForce = bot.placeable.Orientation().Mul(new float3(0, 0, -15)); // TODO Randomize?
                else
                    bot.rigidbody.linearVelocity = bot.placeable.Orientation().Mul(new float3(0, 0, -5)); // TODO Randomize?

                if (HasReachedTarget(bot, targetPos, 0.25))
                    if (++bot.currentWaypoint >= bot.waypoints.length)
                        bot.currentWaypoint = 0; // start over
            }
        }

    profiler.EndBlock();
}

/*
function AnimationUpdate(frameTime)
{
    if (!currentBlock)
        return;
    for(i in currentBlock.bots)
    {
        var bot = currentBlock.bots[i];
        if (!bot.mesh.HasMesh())
            continue; // mesh and/or skeleton not loaded yet

        if (!bot.animationcontroller.IsAnimationActive("Walk"))
            bot.animationcontroller.EnableAnimation("Walk", true, 0.25, false)

        // Scale the current playback speed of the walk animation according to our linear velocity
        me.animationcontroller.SetAnimationSpeed("Walk", 0.3 * me.rigidbody.linearVelocity.Length());
    }
}
*/

// Rotates smoothly (slerp) the bot around the Y-axis towards a target heading in degrees
function TurnToSmooth(entity, targetHeading, weight)
{
    var targetRot = new Quat(new float3(0, 1, 0), targetHeading / (180 / Math.PI));
    entity.placeable.SetOrientation(entity.placeable.Orientation().Slerp(targetRot, weight));
}

// Calculates the heading (rotation arond Y-axis) required to look from the bot's current position to a target
function ComputeTargetHeading(entity, targetPos)
{
    var targetDirection = targetPos.Sub(entity.placeable.WorldPosition());
    targetDirection.y = 0; // for now at least, we're only interested in motion on the XZ plane
    return Math.atan2(-targetDirection.x, -targetDirection.z) * (180 / Math.PI);
}

// Checks if the bot has reached a target position, with a threshold distance given
function HasReachedTarget(entity, targetPos, threshold)
{
    var currentPos = entity.placeable.WorldPosition();
    targetPos.y = currentPos.y = 0; // for now at least, we're only interested in motion on the XZ plane
    return targetPos.Sub(currentPos).Length() < threshold;
}
