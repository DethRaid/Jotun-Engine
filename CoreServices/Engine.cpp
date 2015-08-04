#include "stdafx.h"
#include "Engine.h"


namespace CoreServices {
    Engine::Engine() {
        transformScene.registerSelf( &fileLoader );
    }

    Engine::~Engine() {}

    void Engine::registerSubSystem( ISubsystem *newSubsystem ) {
        subsystems.push_back( newSubsystem );
        newSubsystem->getDataLoader()->registerSelf( &fileLoader );
    }

    void Engine::loadScene( std::string sceneFileName ) {
        fileLoader.loadScene( sceneFileName );
    }

    void Engine::beginGameLoop() {

        tick();
    }

    void Engine::tick() {
        while( true ) {
            clock_t startTime = clock();

            doUpdateAndRender();

            clock_t updateEndTime = clock();
            frameTime += double( updateEndTime - startTime ) / CLOCKS_PER_SEC;

            doPhysics();

            clock_t frameEndTime = clock();
            Time::deltaTime = double( frameEndTime - startTime ) / CLOCKS_PER_SEC;
        }
    }

    void Engine::doUpdateAndRender() {
        for( ISubsystem *sub : subsystems ) {
            sub->onPreRender();
        }

        renderSystem->render();

        for( ISubsystem *sub : subsystems ) {
            sub->update();
        }
    }

    // TODO: I feel like the time won't be exactly right, especially if the physics
    // doesn't take exactly Time::fixedTimeStep seconds to execute
    void Engine::doPhysics() {
        // Consume frame time
        for( frameTime; frameTime > 0.0; frameTime -= Time::fixedTimeStep ) {
            physicsSystem->doPhysics();
            for( ISubsystem *sub : subsystems ) {
                sub->fixedUpdate();
            }
        }

        frameTime += Time::fixedTimeStep;
    }
}
