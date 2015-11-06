#pragma once

namespace core_services {

    class engine;

    /*~\brief Interface for all the subsystems of the Jotunengine or games built with it*/
    class isubsystem {
    public:
        /*!\brief Called when the engine is started
        
        Allows this subsystem to register all its things. This method should handle all the interactions between this
        class and any others which are necessary for this class to work.*/
        virtual void init( engine * ) = 0;

        /*!\brief Called right after a scene file has been loaded*/
        virtual void on_load_scene() = 0;

        /*!\brief Called when a scene is unloaded from RAM*/
        virtual void on_unload_scene() = 0;

        /*!\brief Called right before the renderer is run.*/
        virtual void on_pre_render() = 0;

        /*!\brief Called once per frame. Use for updating game logic*/
        virtual void update() = 0;

        /*!\brief Called every fixed interval*/
        virtual void fixed_update() = 0;

        /*!\brief Called as the engine is closed*/
        virtual void shutdown() = 0;
    };
}
