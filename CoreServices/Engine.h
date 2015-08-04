#pragma once

#include <ctime>
#include <cmath>

#include "TransformScene.h"
#include "SceneFileLoader.h"
#include "IPhysicsSystem.h"
#include "ISubsystem.h"
#include "IRenderSystem.h"

#include "Time.h"

namespace CoreServices {
    class CORESERVICESDLL_API Engine {
    public:
        Engine();
        ~Engine();

        /* Initialization methods */
        void registerSubSystem( ISubsystem *newSubsystem );
        void loadScene( std::string sceneFileName );

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

        double frameTime;

        void tick();
        void doUpdateAndRender();
        void doPhysics();
    };
}
