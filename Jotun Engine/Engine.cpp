#include "engine.h"

#include "render_system_gl45.h"
#include "config.h"

namespace core_services {
    engine::engine() {
        logger = el::Loggers::getLogger( "engine" );

        fileLoader.register_scene_loader( &transformScene );

        logger->debug( "Added transform_scene_loader to file loader" );

        // Initialize the rendering and physics systems
        m_render_system = new renderer::render_system_gl45();
        //register_subsystem( m_render_system );
        m_main_window = m_render_system->get_window();

        logger->info( "Initialized renderer" );
    }

    engine::~engine() {}

    void engine::register_subsystem( ISubsystem *newSubsystem ) {
        subsystems.push_back( newSubsystem );
        fileLoader.register_scene_loader( newSubsystem->get_data_loader() );
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
        for( ISubsystem *sub : subsystems ) {
            sub->update();
        }

        for( ISubsystem *sub : subsystems ) {
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
            for( ISubsystem *sub : subsystems ) {
                sub->fixed_update();
            }
        }

        frameTime += Time::fixedTimeStep;
    }
}
