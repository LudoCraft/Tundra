/** For conditions of distribution and use, see copyright notice in LICENSE

    InfiniteWorld.js - A demo/testbed scene for profiling bottlenecks when dealing with a large world. */

// TODOs:
// 1) Get FireEaters working
// 2) Code cleanup and generic and reusable functions for manipulating the scene block matrix
// 3) Find good terrain size and N for scene block matrix
// 4) Use active cam pos instead of avatar pos
// 5) Find good amount of fire eaters for 
// 6) ...

// from http://my.opera.com/GreyWyvern/blog/show.dml/1725165
/*
Object.prototype.clone = function()
{
    var newObj = (this instanceof Array) ? [] : {};
    for(i in this)
    {
        if (i == 'clone')
            continue;
        if (this[i] && typeof this[i] == "object")
            newObj[i] = this[i].clone();
        else
            newObj[i] = this[i]
    }
    return newObj;
};
*/

// Entry point for the script.
if (server.IsRunning())
{
    // numRows and numCols must be uneven and >= 3: 3,5,7,9,...
    var numRows = 3;
    var numCols = 3;

    // Start point of the scene block matrix.
    var startPos = new float3(0, 0, 0);
    // NOTE: numPatches configurable only if .ntf is also re-authored.
    var numPatches = 8;
    var blockWidth = 16 * numPatches - 1;
    var blockHeight = 128;

    // Init two-dimensional scene block array
    var sceneBlocks = new Array(numRows);
    for(var i = 0; i < numRows; ++i)
        sceneBlocks[i] = new Array(numCols);

    var userEntity = null;
    var previousBlock = null;
    var currentBlock = null;

    Start();
}

// Structure representing one scene block in the NxN scene block matrix.
function SceneBlock(name, row, col, pos)
{
    this.name = name;
    this.row = row;
    this.col = col;
    this.pos = pos;
    this.entities = [];
    this.aabb = new AABB(pos, new float3(pos.x + blockWidth, blockHeight, pos.z + blockWidth));
}

function OnScriptDestroyed()
{
    Stop();
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
        for(var i = 0; i < numRows; ++i)
            for(var j = 0; j < numCols; ++j)
                RemoveSceneBlockAt(i, j/*,false*/);
        sceneBlocks = null;
    }
}

function HandleUserConnected(id, user)
{
    userEntity = scene.GetEntityByName("Avatar" + id);
    if (userEntity)
    {
        var userStartPos;
        var pos = new float3(startPos);
        for(var i = 0; i < numRows; ++i)
            for(var j = 0; j < numCols; ++j)
            {
                var block = InstantiateSceneBlock(pos, i, j);
                sceneBlocks[i][j] = block;

                if (block == CenterBlock())
                    userStartPos = new float3(pos);

                if (j == numCols-1) // Reached end of the row, proceed to next
                {
                    pos.x = startPos.x;
                    pos.z += blockWidth; // backwards +z
                }
                else // Proceed with the row.
                {
                    pos.x += blockWidth; // right +x
                }
            }

        // Position user in the middle of the middle block, add some height so that we don't end up under the terrain.
        userStartPos.x += blockWidth/2;
        userStartPos.y += 40;
        userStartPos.z += blockWidth/2;
        print("UserStartPos " + userStartPos);
        userEntity.placeable.SetPosition(userStartPos);
        userEntity.placeable.SetOrientation(Quat.FromEulerZYX(0,0,0));

        DebugDumpSceneBlocks();
    }
}

function HandleUserDisconnected()
{
    userEntity = null;
    // TODO: cleanup the scene
}

// Finds the scene block user is currently at
function CurrentSceneBlock()
{
    if (!userEntity)
        return null;
    var pos = userEntity.placeable.transform.pos;
    for(var i = 0; i < sceneBlocks.length; ++i)
        for(var j = 0; j < sceneBlocks[i].length; ++j)
            if (sceneBlocks[i][j].aabb.Contains(pos))
                return sceneBlocks[i][j];

    console.LogError("CurrentSceneBlock: could not find where the user at!");
    return null; // Should not happen ever
}

function InstantiateSceneBlock(pos, rowIdx, colIdx)
{
    var sceneBlockFile = "/Assets/SceneBlockOnlyTerrain.txml";
    // Terrain + 1 FireEater:
    //var sceneBlockFile = "/Assets/SceneBlockOneNpc.txml";
    // Terrain + 63 FireEaters:
    //var sceneBlockFile = "/Assets/SceneBlockMultipleNpcs.txml";
    var entities = scene.LoadSceneXML(application.currentWorkingDirectory + sceneBlockFile, false, false, 0);
    if (entities.length == 0)
    {
        console.LogError("InstantiateSceneBlock: Failed to instantiate " + sceneBlockFile);
        return;
    }

    // Set up terrain
    var t = entities[0].terrain.nodeTransformation;
    t.pos = pos;
    entities[0].terrain.nodeTransformation = t;
    var blockName = rowIdx.toString() + "," + colIdx.toString()
    entities[0].name = "Terrain" + blockName;

    // Set up FireEaters
    if (entities.length > 1)
    {
        var fireEaterPos = new float3(pos);
        fireEaterPos.x += blockWidth/2;
        fireEaterPos.y += 40;
        fireEaterPos.z += blockWidth/2;
        entities[1].placeable.SetPosition(fireEaterPos);
    }

    var newBlock = new SceneBlock(blockName, rowIdx, colIdx, pos);
    newBlock.entities = entities;

    console.LogInfo("Scene block " + newBlock.name + " instantiated at " + entities[0].terrain.nodeTransformation.pos);

    return newBlock;
}

function RemoveSceneBlocks(blocks)
{
    for(var i = 0; i < blocks.length; ++i)
        RemoveSceneBlock(blocks[i]);
}

function RemoveSceneBlockAt(row, col/*, saveState*/)
{
    print("Removing block " + row + " " + col);
    // TODO
    // if (saveState) {}
    RemoveSceneBlock(sceneBlocks[row][col]);
}

function RemoveSceneBlock(block)
{
    print("Removing scene block " + block.name);
    for(var i = 0; i < block.entities.length; ++i)
        try
        {
            scene.RemoveEntity(block.entities[i].id);
        }
        catch(e)
        {
            print("RemoveSceneBlock: " + e);
        }

    block  = null;
}

function DebugDumpSceneBlocks()
{
    var str = "";
    for(var i = 0; i < sceneBlocks.length; ++i)
        for(var j = 0; j < sceneBlocks[i].length; ++j)
        {
            str += "[" + sceneBlocks[i][j].name + "]";
            if (j == numCols-1 && i < numRows-1)
                str += "\n";
            else
                str += " ";
        }
    print(str);
}

// Shortcuts
function CenterBlock() { return sceneBlocks[(numRows-1)/2][(numCols-1)/2]; }
function TopRightBlock() { return sceneBlocks[0][numCols-1]; }
function TopLeftBlock() { return sceneBlocks[0][0]; }
function BottomLeftBlock() { return sceneBlocks[numRows-1][0]; }
function BottomRightBlock() { return sceneBlocks[numRows-1][numCols-1]; }
function BottomCenterBlock() { return sceneBlocks[numRows-1][(numCols-1)/2]; }
function CenterRightBlock() { return sceneBlocks[(numRows-1)/2][numCols-1]; }
function TopCenterBlock() { return sceneBlocks[0][(numCols-1)/2]; }
function CenterLeftBlock() { return sceneBlocks[(numRows-1)/2][0]; }

var timer = 0;
var checkInterval = 0; // in seconds

function Update(frameTime)
{

    for(var i in sceneBlocks)
        for(var j in sceneBlocks[i])
            scene.ogre.DebugDrawAABB(sceneBlocks[i][j].aabb, 1, 0, 0);

    if (!userEntity)
        return;

    timer += frameTime;
    if (timer < checkInterval)
        return;
    timer = 0;

    currentBlock = CurrentSceneBlock();
    if (!currentBlock)
        return; // Should happen never

//    print("User is at " + currentBlock.name);

    if (currentBlock != previousBlock && previousBlock != null)
    {
        var dumpState = true;

        var deltaRow = currentBlock.row - previousBlock.row;
        var deltaCol = currentBlock.col - previousBlock.col;
        print("Prev " + previousBlock.name);
        print("Curr " + currentBlock.name);
        print("deltaRow " + deltaRow + " deltaCol " + deltaCol);
        if (dumpState)
        {
            print("WAS:")
            DebugDumpSceneBlocks();
        }

        var oldBlocks = [], newBlocks = [];
        if (deltaRow == 0 && deltaCol > 0) // Moving right
        {
            // Append new column, remove leftmost column (00, 10, 20)
            //print("Append new column, remove leftmost column");
            console.LogInfo("MOVING RIGHT");

            var pos = new float3(TopRightBlock().aabb.minPoint);
            pos.x += deltaCol * blockWidth;

            // Instantiate new blocks
            for(var i = 0; i < numRows; ++i)
            {
                newBlocks.push(InstantiateSceneBlock(pos, i, currentBlock.col+deltaCol)); // +1
                pos.z += blockWidth; // backwards +z
            }

            // Gather blocks to be removed.
            for(var i = 0; i < newBlocks.length; ++i)
                oldBlocks.push(sceneBlocks[i][0]);

            // Re-arrange the scene block matrix.
            // Move columns left, excluding the last column
            for(var col = 0; col < numCols-1; ++col)
                for(var i = 0; i < numRows; ++i)
                    sceneBlocks[i][col] = sceneBlocks[i][col+1];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var i = 0; i < newBlocks.length; ++i)
                sceneBlocks[i][numCols-1] = newBlocks[i];
        }
        else if (deltaRow == 0 && deltaCol < 0) // Moving left
        {
            // Preprend new column, remove rightmost column(2)
            //print("Preprend new column, remove rightmost column");
            console.LogInfo("MOVING LEFT");

            var pos = new float3(TopLeftBlock().aabb.minPoint);
            pos.x += deltaCol * blockWidth;

            // Instantiate new blocks
            for(var i = 0; i < numRows; ++i)
            {
                newBlocks.push(InstantiateSceneBlock(pos, i, currentBlock.col+deltaCol)); //-1
                pos.z += blockWidth;
            }
            // Gather blocks to be removed.
            for(var i = 0; i < newBlocks.length; ++i)
                oldBlocks.push(sceneBlocks[i][numCols-1]);

            // Re-arrange the scene block matrix.
            // Move columns right, excluding the first column
            for(var col = numCols-1; col > 0; --col)
                for(var i = 0; i < numRows; ++i)
                    sceneBlocks[i][col] = sceneBlocks[i][col-1];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var i = 0; i < newBlocks.length; ++i)
                sceneBlocks[i][0] = newBlocks[i];
        }
        else if (deltaRow > 0 && deltaCol == 0) // Moving backwards/"down"
        {
            // Append new row, remove top row 0
            //print("Append new row, remove top row");
            console.LogInfo("MOVING DOWN");

            var pos = new float3(BottomLeftBlock().aabb.minPoint);
            pos.z += deltaRow * blockWidth;

            // Instantiate new blocks
            for(var j = 0; j < numCols; ++j)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, j)); // +1
                pos.x += blockWidth;
            }

            // Gather blocks to be removed (first row)
            for(var j = 0; j < newBlocks.length; ++j)
                oldBlocks.push(sceneBlocks[0][j]);

            // Re-arrange the scene block matrix.
            // Row 1 becomes row 0, row 2 becomes row 1 etc.
            for(var row = 0; row < numRows-1; ++row)
                for(var j = 0; j < numCols; ++j)
                    sceneBlocks[row][j] = sceneBlocks[row+1][j];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var j = 0; j < newBlocks.length; ++j)
                sceneBlocks[numRows-1][j] = newBlocks[j];
        }
        else if (deltaRow < 0  && deltaCol == 0) // Moving forward/"up"
        {
            // Prepend new column, remove bottom row
            //print("Prepend new row, remove bottom row");
            console.LogInfo("MOVING UP");

            var pos = new float3(TopLeftBlock().aabb.minPoint);
            pos.z += deltaRow * blockWidth;

            // Instantiate new blocks
            for(var j = 0; j < numCols; ++j)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, j+deltaCol)); // -1
                pos.x += blockWidth;
            }

            // Gather blocks to be removed (bottom row)
            for(var j = 0; j < newBlocks.length; ++j)
                oldBlocks.push(sceneBlocks[numRows-1][j]);

            // Re-arrange the scene block matrix.
            // Row 1 becomes row 2, row 0 becomes row 1 etc.
            for(var row = numRows-1; row > 0; --row)
                for(var j = 0; j < numCols; ++j)
                    sceneBlocks[row][j] = sceneBlocks[row-1][j];

            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            for(var j = 0; j < newBlocks.length; ++j)
                sceneBlocks[0][j] = newBlocks[j];
        }
        else if (deltaCol > 0 && deltaRow > 0)
        {

            // Append new column and new row, remove leftmost column and topmost row.
            console.LogInfo("MOVING RIGHT AND DOWN");
            var pos = new float3(CenterRightBlock().aabb.minPoint);
            pos.x += deltaCol * blockWidth;

            // Instantiate new blocks
            for(var i = 0; i < numRows; ++i) // TODO Row ja col vituillaan
            {
                newBlocks.push(InstantiateSceneBlock(pos, i+deltaRow, currentBlock.col+deltaCol)); // +1
                pos.z += blockWidth; // backwards +z
            }
            var pos = new float3(BottomCenterBlock().aabb.minPoint);
            pos.z += deltaRow * blockWidth;
            for(var j = 0; j < numCols-1; ++j) // numCols-1, the new bottom right is already instantiated
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, j+deltaCol)); // +1
                pos.x += blockWidth;
            }

            // Gather blocks to be removed.
            for(var i = 0; i < numRows; ++i) // Leftmost column
                oldBlocks.push(sceneBlocks[i][0]);
            for(var j = 1; j < numCols; ++j) // Top row, skip top-left block j=0, as it's already included
                oldBlocks.push(sceneBlocks[0][j]);

            // Re-arrange the scene block matrix: move each element left and up
            // TODO generic approach
            //for(numCols-1)
            sceneBlocks[0][0] = sceneBlocks[1][1];
            sceneBlocks[0][1] = sceneBlocks[1][2];
            //for(numRows-1)
            sceneBlocks[1][0] = sceneBlocks[2][1];
            sceneBlocks[1][1] = sceneBlocks[2][2];

/*
            for(var col = 0; col < numCols-1; ++col)
                for(var i = 0; i < numRows; ++i)
                    sceneBlocks[i][col] = sceneBlocks[i][col+1];
*/
            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            var idx = 0;
            for(var i = 0; idx < numRows; ++idx, ++i)
                sceneBlocks[i][numCols-1] = newBlocks[idx];
            for(var j = 0; idx < newBlocks.length; ++idx, ++j)
                sceneBlocks[numRows-1][j] = newBlocks[idx];
        }
        else if (deltaCol > 0 && deltaRow < 0)
        {
            //Foo(newPosBlockStartBlock, deltaCol, deltaRow, currentBlock)
            // Append new column and new row, remove leftmost column and bottom row
            console.LogInfo("MOVING RIGHT AND UP");
            var pos = new float3(TopCenterBlock().aabb.minPoint);
            //pos.x += deltaCol * blockWidth;
            pos.z += deltaRow * blockWidth;

            for(var j = 0; j < numCols; ++j) // TODO ROW VITUILLEEN
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, j+deltaCol));
                pos.x += blockWidth;
            }
            pos.x -= blockWidth;
            for(var i = 0, row = currentBlock.row; i < numRows-1; ++i, ++row)  // numRows-1, the new top right is already instantiated
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol)); // +1
                pos.z += blockWidth; // backwards +z
            }

            console.LogError(newBlocks.length);
            // Gather blocks to be removed.
            for(var i = 0; i < numRows; ++i) // leftmost column
                oldBlocks.push(sceneBlocks[i][0]);
            for(var j = 1; j < numCols; ++j) // bottom row, skip first as already handled
                oldBlocks.push(sceneBlocks[numRows-1][j]);

            // Re-arrange the scene block matrix: move each element left and down
            // TODO generic approach
            sceneBlocks[2][0] = sceneBlocks[1][1];
            sceneBlocks[2][1] = sceneBlocks[1][2];
            sceneBlocks[1][0] = sceneBlocks[0][1];
            sceneBlocks[1][1] = sceneBlocks[0][2];
/*
            for(var col = 0; col < numCols-1; ++col)
                for(var i = 0; i < numRows; ++i)
                    sceneBlocks[i][col] = sceneBlocks[i][col+1];
*/
            RemoveSceneBlocks(oldBlocks);

            // Add new blocks to the scene block matrix
            var idx = 0;
            for(var j = 0; idx < numCols-1; ++idx, ++j)
            {
                print("0,"+ j + " <- " + newBlocks[idx].name);
                sceneBlocks[0][j] = newBlocks[idx];
            }
            for(var i = 0; idx < newBlocks.length; ++idx, ++i)
            {
                print(i + ","+ (numCols-1) + " <- " + newBlocks[idx].name);
                sceneBlocks[i][numCols-1] = newBlocks[idx];
            }

        }
        else if (deltaCol < 0 && deltaRow > 0)
        {
            // Preprend new column, remove rightmost column
            // Append new row, remove top row
            console.LogInfo("MOVING LEFT AND DOWN");

            var pos = new float3(BottomCenterBlock().aabb.minPoint);
            pos.z += blockWidth;
            // instantiate new bottom row from right to left
            var lastCol;
            // TODO row vituillaan!
            for(var j = numCols, col = BottomCenterBlock().col; j > 0; --j, --col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, currentBlock.row+deltaRow, col));
                //if ()
                    pos.x -= blockWidth;
            }
            pos.x += blockWidth;
            pos.z -= blockWidth;
            // instantiate new leftmost column from down to up
            for(var i = numRows-1, row = numRows-1; i > 0; --i, --row) // numRows-1 as bottom left already instantiated
            {
                newBlocks.push(InstantiateSceneBlock(pos, row, currentBlock.col+deltaCol));
                pos.z -= blockWidth;
            }

            // Gather blocks to be removed.
            for(var j = 0; j < numRows; ++j) // top row
                oldBlocks.push(sceneBlocks[0][j]);
            for(var i = 1; i < numCols; ++i)  // rightmost column
                oldBlocks.push(sceneBlocks[i][numCols-1]);

            // Re-arrange the scene block matrix: Move each element right and up
            sceneBlocks[0][1] = sceneBlocks[1][0];
            sceneBlocks[0][2] = sceneBlocks[1][1];
            sceneBlocks[1][1] = sceneBlocks[2][0];
            sceneBlocks[1][2] = sceneBlocks[2][1];

            RemoveSceneBlocks(oldBlocks);

            // Insert new blocks.
            var idx = 0;
            for(var j = numCols-1; j >= 0; --j)
                sceneBlocks[numRows-1][j] = newBlocks[idx++];
            for(var i = numRows-1-1; i >= 0; --i)
                sceneBlocks[i][0] = newBlocks[idx++];
        }
        else if (deltaCol < 0 && deltaRow < 0)
        {
            // Preprend new column, remove rightmost column and bottom row
            console.LogInfo("MOVING LEFT AND UP");
            
            var pos = new float3(CenterLeftBlock().aabb.minPoint);
            pos.x += deltaCol * blockWidth;

            // Add new leftmost column
            var lastRow, lastCol = CenterLeftBlock().col - 1;
            for(var i = 0, row = CenterLeftBlock().row; i < numRows; ++i, --row)
            {
                var b = InstantiateSceneBlock(pos, row, lastCol);
                newBlocks.push(b);
                if (i < numRows-1)
                    pos = pos.Add(scene.ForwardVector().Mul(blockWidth));
                lastRow = b.row;
            }
            // Add new top row, skip top left, already instantiated
            pos = pos.Add(scene.RightVector().Mul(blockWidth));
            for(var j = 1, col = lastCol+1; j < numCols; ++j, ++col)
            {
                newBlocks.push(InstantiateSceneBlock(pos, lastRow, col));
                pos.Add(scene.RightVector().Mul(blockWidth));
            }

            // Gather blocks to be removed
            for(var j = 0; j < numCols; ++j) // bottom row
                oldBlocks.push(sceneBlocks[numRows-1][j]);
            for(var i = 0; i < numRows-1; ++i) // rightmost column
                oldBlocks.push(sceneBlocks[i][numCols-1]);

            // Re-arrange the scene block matrix: move each element right and down
            //MoveBlock(1,0, 2, 1);
            //MoveBlock(1,1, 2, 1);
            //MoveBlock(0,0, 1, 1);
            //MoveBlock(0,1, 1, 2);
            sceneBlocks[2][1] = sceneBlocks[1][0];
            sceneBlocks[2][2] = sceneBlocks[1][1];
            sceneBlocks[1][1] = sceneBlocks[0][0];
            sceneBlocks[1][2] = sceneBlocks[0][1];

            RemoveSceneBlocks(oldBlocks);

            //Move(fromRow, fromCol, toRow, toCol, rowDirection, columnDirection)
            var idx = 0;
            for(var j = numCols-1; j >= 0 ; --j)
                sceneBlocks[numRows-1][j] = newBlocks[idx++];
            for(var i = numRows-1-1; i >= 0; --i)
                sceneBlocks[i][0] = newBlocks[idx++];

        }
        else
        {
            console.LogError("SHOULD NOT END UP HERE EVER!");
        }

        if (dumpState)
        {
            print("IS:")
            DebugDumpSceneBlocks();
        }
    }

    previousBlock = currentBlock;
}

function MoveBlock(oldRow, oldCol, newRow, newCol)
{
    sceneBlocks[oldRow][oldCol] = sceneBlocks[newRow][newCol];
}

