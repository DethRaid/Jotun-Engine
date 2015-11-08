#pragma once
#include "stdafx.h"

#include <tuple>

#include <GL/GLFW/glfw3.h>

#include "IRenderSystem.h"
#include "render_data_store.h"
#include "sdl_window.h"
#include "component_loader.h"
#include "engine.h"

namespace renderer {
    class render_system_gl45 : public core_services::irender_system {
    public:
        /*!\brief Initializes the rendering system, allowing the rendering system to register all its listeners and loaders and whatnot*/
        render_system_gl45( core_services::engine *engine );
        ~render_system_gl45();

        /* Inherited from irender_system */
        virtual void render();
        virtual core_services::iwindow* get_window();

        /* Inherited from isubsystem */
        virtual void init( core_services::engine *engine );
        virtual void on_load_scene();
        virtual void on_unload_scene();
        virtual void on_pre_render();
        virtual void update();
        virtual void fixed_update();
        virtual void shutdown();

    private:
        sdl_window *m_window;
        render_data_store m_data_store;
    };
}
