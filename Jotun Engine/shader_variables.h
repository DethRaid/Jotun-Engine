#pragma once
#include "stdafx.h"
#include "glad.h"

namespace Renderer {
    class shader_variable {
    public:
        shader_variable( std::string& name, GLuint gl_name );

        virtual void upload_data( void* data ) = 0;
    protected:
        std::string m_name;
        GLuint m_gl_name;
    };

    class int_shader_variable : public shader_variable {
        int_shader_variable( std::string& name, GLuint gl_name );

        virtual void upload_data( void* data );
    };

    class float_shader_variable : public shader_variable {
        float_shader_variable( std::string& name, GLuint gl_name );

        virtual void upload_data( void* data );
    };

    class float3_shader_variable : public shader_variable {
        float3_shader_variable( std::string& name, GLuint gl_name );

        virtual void upload_data( void* data );
    };

    class mat4_shader_variable : public shader_variable {
        mat4_shader_variable( std::string& name, GLuint gl_name );

        virtual void upload_data( void* data );
    };
}
