#include "engine.h"

#include "render_system_gl45.h"
#include "config.h"

namespace core_services {
    engine::engine() {
        fileLoader.register_component_loader( &transformScene );
        
        // Initialize the rendering and physics systems
        m_render_system = new renderer::render_system_gl45( this );

        LOG( INFO ) << "Initialized renderer\n";
    }

    engine::~engine() {}

    void engine::register_subsystem( isubsystem *new_subsystem ) {
        new_subsystem->init( this );
        subsystems.push_back( new_subsystem );
    }

    void engine::load_scene( std::string sceneFileName ) {
        fileLoader.loadScene( sceneFileName );
    }

    void engine::begin_game_loop() {

        tick();
    }

    SceneFileLoader & engine::get_scene_file_loader() {
        return fileLoader;
    }

    transform_scene & engine::get_transform_scene() {
        return transformScene;
    }

    void engine::set_window( iwindow *window ) {
        m_main_window = window;
    }

    void engine::tick() {
        while( !m_main_window->should_close() ) {
            std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();

            doUpdateAndRender();

            std::chrono::system_clock::time_point updateEndTime = std::chrono::system_clock::now();
            frameTime += updateEndTime - startTime;

            doPhysics();

            std::chrono::system_clock::time_point frameEndTime = std::chrono::system_clock::now();

            //Time::deltaTime = frameEndTime - startTime;
        }
    }

    void engine::doUpdateAndRender() {
        for( isubsystem *sub : subsystems ) {
            sub->update();
        }

        for( isubsystem *sub : subsystems ) {
            sub->on_pre_render();
        }

        m_render_system->render();
    }

    // TODO: I feel like the time won't be exactly right, especially if the physics
    // doesn't take exactly Time::fixedTimeStep seconds to execute
    void engine::doPhysics() {
        // Consume frame time
        for( frameTime; frameTime > std::chrono::duration<int, std::milli>( 0 ); frameTime -= Time::fixedTimeStep ) {
            physicsSystem->do_physics();
            for( isubsystem *sub : subsystems ) {
                sub->fixed_update();
            }
        }

        frameTime += Time::fixedTimeStep;
    }
}
