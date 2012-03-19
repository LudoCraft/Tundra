engine.IncludeFile("class.js");

var AiWanderer = Class.extend({

    // Default constructor 

    init: function() {

        // Intialise Environment
        var terrain_entity = scene.GetEntitiesWithComponent("EC_Terrain")[0];
        if (terrain_entity != null && typeof (terrain_entity) != "undefined") {
            this.terrain_ = terrain_entity.GetComponent("EC_Terrain");
        }
        else
            this.terrain_ = null;

        this.placeable_ = me.GetComponent("EC_Placeable");

        // Animation controller 
        this.anim_ = me.GetComponent("EC_AnimationController");

        // Object itself.
        this.walking_ = false;
        this.gesture_ = false;
        this.frameTime_ = 0;
        this.actionStopTime_ = -1;
        this.currentAction_ = null;
        /// This defines how "near" for correct direction angle we turn.
        this.directionDelta_ = 0.025;
    },

    // Helper function which is called just after walk animation is started. Override this in subclass
    // if there exist a reason for updating internal attributes.
    // @param time is frametime. 

    UpdateInternals: function(time) {
        //empty
    },

    // Returns next action what wanderer ai will do next. 
    // This should be overrided in subclass.

    GetAction: function() {
        print("AiWanderer GetAction() : default");
        var action = { time: 10, name: "Default", type: "default", maxTime: 10, minTime: 5, loop: true };
        return action;
    },

    // Returns distance to terrain.
    // @param transform is transform object in world coordinate system.

    GetDistanceToTerrain: function(transformation) {

        if (this.terrain_ == null)
            return 0;

        return this.terrain_.GetDistanceToTerrain(transformation.pos);
    },

    /// Slerps direction angle.
    /// Helper function which can be used for calculating smooth turn for terrain wanderer object.
    /// @param current is current direction angle (can be radians, degrees)
    /// @param target is target angle.
    /// @param speed is object angular speed (turning speed)
    /// @param time is time which object turns on tick. 

    SlerpDirectionAngle: function(current, target, speed, time) {

        if (Math.abs(target - current) < this.directionDelta_) {
            return current;
        }

        var angle = 0;
        if (target > current) {
            angle = current + speed * time;
        }
        else if (target < current) {
            angle = current - speed * time;
        }

        return angle;

    },


    /// Returns true if point in world coordinate system is inside given volume.

    IsInsideVolume: function(point, volume) {

        if (volume != null) {
            return volume.IsInsideVolume(point);
        }
        return false;
    },

    /// Returns all volumes (EC_VolumeTrigger-components) which EC_Name attribute is given name
    GetTriggerVolumes: function(name) {
        var entities = scene.GetEntitiesWithComponent("EC_Name");
        var volumes = [];
        for (var i = 0; i < entities.length; ++i) {

            var ent = entities[i];
            var comp = ent.GetComponent("EC_Name");
            if (comp.name == name) {
                var volume = ent.GetComponent("EC_VolumeTrigger");
                if (volume != null) {
                    volumes.push(volume);
                }
            }
        }

        return volumes;
    },

    /// Returns true if point is inside any volume.
    IsInsideAnyVolume: function(point) {

        var entities = scene.GetEntitiesWithComponent("EC_VolumeTrigger");
        for (var i = 0; i < entities.lenght; ++i) {
            var ent = entities[i];
            var volume = ent.GetComponent("EC_VolumeTrigger");
            if (IsInsideVolume(point, volume))
                return true;
        }
    },

    // Runs a given "gesture" action on entity.

    Gesture: function(action) {

        if (!this.gesture_ && action.name == "Default") {
            print("WandererAi Gesture():  default action (do nothing)");
            return;
        }

        this.UpdateInternals(this.frameTime_);

        if (!this.gesture_) {
            //print("WandererAI : Gesture() Change gesture animation");
            me.Exec(7, "StopAllAnims", "0.8");
            if (action.loop) {
                me.Exec(7, "PlayLoopedAnim", action.type, "0.8");
                me.Exec(7, "SetAnimSpeed", action.type, action.speed);
            } else {
                me.Exec(7, "PlayAnim", action.type,  "0.8");
                me.Exec(7, "SetAnimSpeed", action.type, action.speed);
            }

            this.walking_ = false;
            this.gesture_ = true;
        }
    },

    // Function which is called if action type was "walk" action.

    Walk: function(action) {

        if (!this.walking_) {

            me.Exec(7, "StopAllAnims", "0.8");
            if (action.loop) {
                me.Exec(7, "PlayLoopedAnim", action.type, "0.8");
                me.Exec(7, "SetAnimSpeed", action.type, action.speed);
            } else {
                me.Exec(7, "PlayAnim", action.type, "0.8");
                me.Exec(7, "SetAnimSpeed", action.type, action.speed);
            }

            this.walking_ = true;
            this.gesture_ = false;
            this.UpdateInternals(this.frameTime_);
        }

        this.WalkTo(this.frameTime_);

    },

    /// Sets entity placeable to new position, should be overrided in subclass.
    /// by default does not do anything.
    /// @param time is frametime.

    WalkTo: function(time) {
        print("WandererAi WalkTo()");
    },

    // Runs a given action. 
    // @param action which should be runned.

    RunAction: function(action) {

        if (action.name == "walk" || action.name == "Walk" || action.name == "WalkForward" || action.name == "WalkBackward" || action.name == "Dive" || action.name == "Surface")
            this.Walk(action);
        else
            this.Gesture(action);


    },

    // Update loop, this loop should be called in function which is connected to frame update signal.

    Update: function(frametime) {

        var currentTime = frame.WallClockTime();
        this.frameTime_ = frametime;

        if (this.actionStopTime_ == -1) {

            // First time when update loop is called, intialise action.
            this.currentAction_ = this.GetAction();
            this.actionStopTime_ = frame.WallClockTime() + this.currentAction_.time;
        }

        //print("Update() Time left for new action : " + (this.actionStopTime_ - currentTime) + " ");

        if (currentTime < this.actionStopTime_) {
            // If time left run one-round current action.
            this.RunAction(this.currentAction_);
        }
        else {

            this.walking_ = false;
            this.gesture_ = false;

            // Get new action.
            this.currentAction_ = this.GetAction();
            this.actionStopTime_ = frame.WallClockTime() + this.currentAction_.time;

            // Run new action.
            this.RunAction(this.currentAction_);

        }

    }

});





