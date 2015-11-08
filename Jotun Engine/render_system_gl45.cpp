#include "render_system_gl45.h"

namespace renderer {
    render_system_gl45::render_system_gl45( core_services::engine *engine ) {
        m_window = new sdl_window( 4, 5 );

        gladLoadGL();

        init( engine );
    }

    render_system_gl45::~render_system_gl45() {}

    void render_system_gl45::render() {}

    core_services::iwindow* render_system_gl45::get_window() {
        return m_window;
    }

    void render_system_gl45::init( core_services::engine *engine ) {
        engine->set_window( m_window );
        engine->get_scene_file_loader().register_data_loader( "render_data", &m_data_store );
    }

    void render_system_gl45::on_load_scene() {}
    void render_system_gl45::on_unload_scene() {}
    void render_system_gl45::on_pre_render() {}
    void render_system_gl45::update() {}
    void render_system_gl45::fixed_update() {}
    void render_system_gl45::shutdown() {}
}