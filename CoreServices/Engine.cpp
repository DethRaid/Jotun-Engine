#include "Engine.h"

namespace CoreServices {
    Engine::Engine() {
        fileLoader.register_scene_loader( &transformScene );
    }

    Engine::~Engine() {}

    void Engine::registerSubSystem( ISubsystem *newSubsystem ) {
        subsystems.push_back( newSubsystem );
        fileLoader.register_scene_loader( newSubsystem->get_data_loader() );
    }

    void Engine::load_scene( std::string sceneFileName ) {
        fileLoader.loadScene( sceneFileName );
    }

    void Engine::beginGameLoop() {

        tick();
    }

    SceneFileLoader & Engine::getSceneFileLoader() {
        return fileLoader;
    }

    TransformScene & Engine::getTransformScene() {
        return transformScene;
    }

    void Engine::tick() {
        while( true ) {
            std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();

            doUpdateAndRender();

            std::chrono::system_clock::time_point updateEndTime = std::chrono::system_clock::now();
            frameTime += updateEndTime - startTime;

            doPhysics();

            std::chrono::system_clock::time_point frameEndTime = std::chrono::system_clock::now();

            Time::deltaTime = frameEndTime - startTime;
        }
    }

    void Engine::doUpdateAndRender() {
        for( ISubsystem *sub : subsystems ) {
            sub->update();
        }

        for( ISubsystem *sub : subsystems ) {
            sub->on_pre_render();
        }

        renderSystem->render();
    }

    // TODO: I feel like the time won't be exactly right, especially if the physics
    // doesn't take exactly Time::fixedTimeStep seconds to execute
    void Engine::doPhysics() {
        // Consume frame time
        for( frameTime; frameTime > std::chrono::duration<int, std::milli>( 0 ); frameTime -= Time::fixedTimeStep ) {
            physicsSystem->doPhysics();
            for( ISubsystem *sub : subsystems ) {
                sub->fixed_update();
            }
        }

        frameTime += Time::fixedTimeStep;
    }
}
