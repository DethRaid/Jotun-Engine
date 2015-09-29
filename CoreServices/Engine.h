#pragma once

#include "stdafx.h"

#include "TransformScene.h"
#include "SceneFileLoader.h"
#include "IPhysicsSystem.h"
#include "ISubsystem.h"
#include "IRenderSystem.h"

namespace CoreServices {

    class Engine {
    public:
        Engine();
        ~Engine();

        /* Initialization methods */
        void registerSubSystem( ISubsystem *newSubsystem );
        void load_scene( std::string sceneFileName );

        /* Run methods */
        void beginGameLoop();

        /* Getters (and setters, if need be) */
        SceneFileLoader & getSceneFileLoader();
        TransformScene & getTransformScene();
    private:
        SceneFileLoader fileLoader;
        TransformScene transformScene;
        std::vector<ISubsystem*> subsystems;
        IRenderSystem *renderSystem;
        IPhysicsSystem *physicsSystem;

        std::chrono::system_clock::duration frameTime;

        void tick();
        void doUpdateAndRender();
        void doPhysics();
    };
}
