#include "render_system_gl45.h"

namespace renderer {
    render_system_gl45::render_system_gl45() {
        logger = el::Loggers::getLogger( "render_system_gl45" );

        m_window = new sdl_window( 4, 5 );

        gladLoadGL();

        logger->info( "Initialized window with OpenGL version %d %d\n", GLVersion.major, GLVersion.minor );
    }

    render_system_gl45::~render_system_gl45() {}


    void render_system_gl45::render() {}

    core_services::iwindow* render_system_gl45::get_window() {
        return m_window;
    }

    void render_system_gl45::init() {}
    void render_system_gl45::on_load_scene() {}
    void render_system_gl45::on_unload_scene() {}
    void render_system_gl45::on_pre_render() {}
    void render_system_gl45::update() {}
    void render_system_gl45::fixed_update() {}
    void render_system_gl45::shutdown() {}

    core_services::component_loader* render_system_gl45::get_data_loader() {
        return NULL;
    }
}