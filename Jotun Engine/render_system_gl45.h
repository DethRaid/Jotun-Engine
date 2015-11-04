#pragma once
#include "stdafx.h"

#include <tuple>

#include <GL/GLFW/glfw3.h>

#include "IRenderSystem.h"
#include "sdl_window.h"
#include "component_loader.h"

namespace renderer {
    class render_system_gl45 : public core_services::irender_system {
    public:
        render_system_gl45();
        ~render_system_gl45();

        /* Inherited from irender_system */
        virtual void render();
        virtual core_services::iwindow* get_window();

        /* Inherited from isubsystem */
        virtual void init();
        virtual void on_load_scene();
        virtual void on_unload_scene();
        virtual void on_pre_render();
        virtual void update();
        virtual void fixed_update();
        virtual void shutdown();
        virtual core_services::component_loader* get_data_loader();

    private:
        sdl_window *m_window;

        el::Logger *logger;
    };
}
