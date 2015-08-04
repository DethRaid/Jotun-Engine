#pragma once

#include "ISceneLoader.h"

namespace CoreServices {
    class ISceneLoader;

    /*~\brief Interface for all the subsystems of the JotunEngine or games built with it*/
    class ISubsystem {
    public:
        /*~\brief Called when the engine is started*/
        virtual void init() = 0;

        /*!\brief Called right after a scene file has been loaded*/
        virtual void onLoadScene() = 0;

        /*!\brief Called when a scene is unloaded from RAM*/
        virtual void onUnloadScene() = 0;

        /*!\brief Called right before the renderer is run.*/
        virtual void onPreRender() = 0;

        /*!\brief Called once per frame. Use for updating game logic*/
        virtual void update() = 0;

        /*!\brief Called every fixed interval*/
        virtual void fixedUpdate() = 0;

        /*!\brief Called as the engine is closed*/
        virtual void shutdown() = 0;

        /*!\brief Returns the ISceneLoader this subsystem uses to load all its data*/
        virtual ISceneLoader* getDataLoader() = 0;
    };
}
