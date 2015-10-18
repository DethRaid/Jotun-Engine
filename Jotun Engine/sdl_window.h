#pragma once

#include "stdafx.h"
#include "iwindow.h"

#include <SDL/SDL.h>

namespace renderer {
    class sdl_window : public core_services::iwindow {
    public:
        sdl_window( int gl_version_major, int gl_version_minor );
        ~sdl_window();

        /* Inherited from iwindow */
        virtual bool should_close();
        virtual void update_window();
    private:
        SDL_Window *m_window;
        SDL_GLContext m_context;

        el::Logger *logger;

        void check_sdl_error( int line = -1 );
    };
}
