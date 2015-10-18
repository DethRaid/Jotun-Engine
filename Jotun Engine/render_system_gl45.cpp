#include "render_system_gl45.h"

namespace renderer {
    render_system_gl45::render_system_gl45() {
        logger = el::Loggers::getLogger( "render_system_gl45" );

        window = new sdl_window( 4, 5 );

        logger->info( "Initialized window with OpenGL version 4.5" );
    }

    render_system_gl45::~render_system_gl45() {}


    void render_system_gl45::render() {}

    core_services::iwindow* render_system_gl45::get_window() {
        return window;
    }

    void render_system_gl45::init() {}
    void render_system_gl45::on_load_scene() {}
    void render_system_gl45::on_unload_scene() {}
    void render_system_gl45::on_pre_render() {}
    void render_system_gl45::update() {}
    void render_system_gl45::fixed_update() {}
    void render_system_gl45::shutdown() {}

    core_services::ISceneLoader* render_system_gl45::get_data_loader() {
        return NULL;
    }
}