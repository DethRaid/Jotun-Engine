#include "sdl_window.h"
#include <string>

namespace renderer {
    sdl_window::sdl_window( int gl_version_major, int gl_version_minor ) {
        int err;
        if( !(err = SDL_Init( SDL_INIT_VIDEO )) ) {
            logger->fatal( "SDL video initialization failed" );
            return;
        }

        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, gl_version_major );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, gl_version_minor );

        // Enable double buffering with a 32-bit depth buffer
        SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
        SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 32 );

        if( !(m_window = SDL_CreateWindow( "SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                           512, 512, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN )) ) {
            logger->fatal( "GLFW window creation failed" );
            return;
        }

        check_sdl_error( __LINE__ );

        m_context = SDL_GL_CreateContext( m_window );
        check_sdl_error( __LINE__ );

        // Enable vsync
        SDL_GL_SetSwapInterval( 1 );
    }

    sdl_window::~sdl_window() {
        SDL_GL_DeleteContext( m_context );
        SDL_DestroyWindow( m_window );
    }

    bool sdl_window::should_close() {
        return false;
    }

    void sdl_window::update_window() {
        SDL_GL_SwapWindow( m_window );
    }

    void sdl_window::check_sdl_error( int line ) {
        std::string error = SDL_GetError();
        
        if( error.size() > 0 ) {
            logger->error( "SDL Error: %s\n", error );
            if( line != -1 ) {
                logger->error( "\tAt line %d\n", line );
            }
            SDL_ClearError();
        }
    }
}