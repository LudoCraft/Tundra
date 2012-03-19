
engine.IncludeFile("AiWanderer.js");

// !ref: fire_stick.particle
// !ref: fire.particle
// !ref: fire_breather.ogg

var FireEater = AiWanderer.extend({
    init: function() {
      
        // Remember call this, initialises base class.
        this._super();

        this.r_ = 20;
        this.actions_ = 4;
        this.speed_ = 1.2; // (dimensions m/s )
        this.currentDirection_ = this.r_;
        this.angularSpeed_ = 1.8;
        this.placeable_ = me.placeable;

        // Set position in circus scene.
        // Note: disabled, as we want to set this ourselves -Stinkfist
        /*
        var tm = this.placeable_.transform;
        tm.pos.x = 10.77;
        tm.pos.y = -0.03;
        tm.pos.z = -0.2;
        me.placeable.transform = tm;
        */
        this.orginalPos_ = me.placeable.transform.pos;
        this.chooseFireAction_ = false;

        this.maxDistance_= 1.5;

        this.particleEffectRunTime_ = 2.5;
        this.particleEffectStartTime_ = 2.5;
       
        this.fireEaterID_ = me.id;//1;
        this.rigidBody_ = null;
        this.fireEffectRunning_ = false;

         /*
        if ( me.GetComponent("EC_RigidBody") == null)
        {
            this.rigidBody_ = me.GetOrCreateComponent("EC_RigidBody");
            this.rigidBody_.shapeType = 2;
            var s = new float3(1.0,4.0,1.0);
            this.rigidBody_.size = s;
        }
        */
        this.RunStickFireParticleEffect();
     
    },

    GetAction: function() {
       
        var index = 1;

        if (this.chooseFireAction_ == false) {
             //We are bottom on sea, so choose randomly.
            index = Math.floor(Math.random() * this.actions_ + 1);
        }
        else {
            index = 2;
            this.chooseFireAction_ = false;
        }
        
        if (index == 1) {
            action = { time: 10, name: "WalkForward", type: "walk", maxTime: 3, minTime: 2, loop: true , speed : 0.6};
        }
        else if (index == 2) {
           action = { time: 5, name: "Fire", type: "breath", maxTime: 1, minTime: 1, loop: false , speed : 1.4 };
        }
        else if (index == 3) {
            action = { time: 5, name: "FeelIt", type: "feel_it_burn", maxTime: 3, minTime: 3, loop: false, speed : 1.5 };
        }
        else if (index == 4) {
            action = { time: 5, name: "ThrowingStick", type: "throwing_stick", maxTime: 6, minTime: 3, loop: true , speed : 1.5};
        }
        else if (index == 5) {
              action = { time: 5, name: "Thanks", type: "thx", maxTime: 3, minTime: 3, loop: false, speed : 1.3 };
        } 
        

        if (action.loop)
            action.time = Math.floor(Math.random() * action.maxTime + action.minTime);

    
        return action;
            
    },
        
    RunStickFireParticleEffect: function()
    {
        var entity = scene.CreateEntity(scene.NextFreeId(), ["EC_Placeable"]);
        var name = "FireStick_" + this.fireEaterID_;
        entity.SetName(name);
        entity.SetTemporary(true);

        var placeable = entity.GetComponent("EC_Placeable");
        var parent = placeable.parentRef; 
        parent.ref = me.id;
        placeable.parentRef = parent;
        placeable.parentBone = "bone_firestick";

        var tm = placeable.transform; 
        tm.pos.x = 0.38;
        tm.rot.z = 270;
        placeable.transform = tm;

        var parOne = entity.GetOrCreateComponent("EC_ParticleSystem");
        var parRef = parOne.particleRef;
        parRef.ref = "fire_stick.particle";
        parOne.particleRef = parRef;

    },
       
    WalkTo: function(time) {
  
        var tm = me.placeable.transform;
        this.placeable_ = me.placeable;
        //var angle = this.r_;
        var angle = this.SlerpDirectionAngle(this.currentDirection_, this.r_, this.angularSpeed_,time);    
       
        tm.rot.y = -angle * 180/Math.PI; 
        tm.pos.x += this.speed_ * time * Math.cos(angle);
        tm.pos.z += this.speed_ * time * Math.sin(angle);
       
        if (this.currentAction_.name == "WalkForward")
        {
             var distanceToTerrain = this.GetDistanceToTerrain(tm);
             tm.pos.y -= distanceToTerrain;
        }
         
      
        //if ( this.rigidBody_ != null && !this.rigidBody_.IsActive())
        //     this.rigidBody_.Activate();
        
        // Set entity new position.
        me.placeable.transform = tm;
        this.currentDirection_ = angle;       
      
    },
    
    UpdateInternals: function(time) {
        
        if ( this.currentAction_.name == "Fire" )
        {
            if ( !this.fireEffectRunning_ )
            {
                //var anim = me.GetComponent("EC_AnimationController");
                //var currentTime = anim.GetAnimationTimePosition(this.currentAction_.type);
                frame.DelayedExecute(this.particleEffectStartTime_).Triggered.connect(this,  this.RunFireParticleEffects);
                this.fireEffectRunning_ = true;
                /*
                if ( this.particleEffectStartTime_ <= currentTime && currentTime <= (this.particleEffectStartTime_ + this.particleEffectRunTime_ ))
                {
                    this.RunFireParticleEffects();
                }
                */
            }
             
        }
        else if ( this.currentAction_.name == "WalkForward" )
        {
        
            // Update direction
            for ( var i = 0; i < 100; ++i)
            {
                this.r_ = Math.random() * 2 * Math.PI;
                if ( this.CheckDirection() )
                {
                    return;
                }
            
            }
            // Check that new direction is that kind that after action our entity is inside trigger volume.
            
            var tm = me.placeable.transform;
          
            var target = new float3(this.orginalPos_.x - tm.pos.x, 0, this.orginalPos_.z - tm.pos.z);
            this.r_ = Math.atan2(target.z, target.x);
            
        }
        
     },
     
     
     StopFireParticleEffects: function() {
            var entity = scene.GetEntityByName("Fire_" + this.fireEaterID_);
            scene.RemoveEntity(entity.id); 
            this.fireEffectRunning_ = false;
     },
    
     RunFireParticleEffects: function() {
        
        me.Exec(4, "PlaySound"); 
        var entity = scene.CreateEntity(scene.NextFreeId(), ["EC_Placeable"]);
        var name = "Fire_" + this.fireEaterID_;
        entity.SetName(name);
        entity.SetTemporary(true);
          
          
        var placeable = entity.GetComponent("EC_Placeable");
        var parent = placeable.parentRef; 
        parent.ref = me.id;
        placeable.parentRef = parent;
        placeable.parentBone = "Bip01 Head";

          
        var parOne = entity.GetOrCreateComponent("EC_ParticleSystem");
        var parRef = parOne.particleRef;
        parRef.ref = "fire.particle";
        parOne.particleRef = parRef;
        this.fireEffectRunning_ = true;
        frame.DelayedExecute(this.particleEffectRunTime_).Triggered.connect(this, this.StopFireParticleEffects);      
    },
    
    CheckDirection : function() {
        
        var tm = me.placeable.transform;
        
        // Calculate new position.
        tm.pos.x += this.speed_ * this.currentAction_.time * Math.cos(this.r_);
        tm.pos.z += this.speed_ * this.currentAction_.time * Math.sin(this.r_);
        tm.pos.y -= this.GetDistanceToTerrain(tm);
        
        if (this.CheckPosition(tm.pos))
            return true;
     
     },
     
     
      CheckPosition: function(point) {
        
            var distance =  (this.orginalPos_.x - point.x)* (this.orginalPos_.x - point.x)+(this.orginalPos_.y - point.y)* (this.orginalPos_.y - point.y) +(this.orginalPos_.z - point.z)* (this.orginalPos_.z - point.z);
            if ( distance > this.maxDistance_)
                return false;
           
            
            return true;
            
    },

     
});

if ( server != null && server.IsRunning() )
{

    var p_ = new FireEater;

    function Update(frametime) {
   
        // Clamp frametime this happens only in when scene is initialised.
        if ( frametime > 5.0 )
            frametime = 0.06
            
        p_.Update(frametime);

    }

    function ToggleFireOn()
    {
        if ( p_ != null )
        {
          if(!p_.fireEffectRunning_)
          {
              p_.chooseFireAction_ = true;
              p_.actionStopTime_ = 0;
          }
        }
    }

    frame.Updated.connect(Update);
    me.Action("ToggleFire").Triggered.connect(ToggleFireOn);
}

function ToggleAction()
{
    me.Exec(2, "ToggleFire"); 
}

function PlaySound()
{
    audio.PlaySound3D(me.placeable.transform.pos, asset.GetAsset("fire_breather.ogg"));
}

me.Action("MousePress").Triggered.connect(ToggleAction);

if(!server.IsRunning())
{
    me.Action("PlaySound").Triggered.connect(PlaySound);
}
