#include "shader_variables.h"

namespace Renderer {
    shader_variable::shader_variable( std::string& name, GLuint gl_name ) {
        m_name = name;
        m_gl_name = gl_name;
    }

    int_shader_variable::int_shader_variable( std::string& name, GLuint gl_name ) :
        shader_variable( name, gl_name ) {}

    float_shader_variable::float_shader_variable( std::string& name, GLuint gl_name ) :
        shader_variable( name, gl_name ) {}

    float3_shader_variable::float3_shader_variable( std::string& name, GLuint gl_name ) :
        shader_variable( name, gl_name ) {}

    mat4_shader_variable::mat4_shader_variable( std::string& name, GLuint gl_name ) :
        shader_variable( name, gl_name ) {}

    void int_shader_variable::upload_data( void* data ) {
        glUniform1i( m_gl_name, *((GLint*)data) );
    }

    void float_shader_variable::upload_data( void* data ) {
        glUniform1f( m_gl_name, *((GLfloat*)data) );
    }

    void float3_shader_variable::upload_data( void* data ) {
        glUniform1fv( m_gl_name, 1, (GLfloat*)data );
    }

    void mat4_shader_variable::upload_data( void* data ) {
        glUniformMatrix4fv( m_gl_name, 1, GL_FALSE, (GLfloat*)data );
    }
}