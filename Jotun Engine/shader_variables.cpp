#include "shader_variables.h"

namespace renderer {
    shader_variable::shader_variable( std::string var_type ) {
        if( var_type == "int" ) {
            m_type = INT;

        } else if( var_type == "float" ) {
            m_type = FLOAT;

        } else if( var_type == "vec3" ) {
            m_type = VEC3;

        } else if( var_type == "vec4" ) {
            m_type = VEC4;

        } else if( var_type == "mat3" ) {
            m_type = MAT3;

        } else if( var_type == "mat4" ) {
            m_type = MAT4;

        } else if( var_type == "sampler2D" ) {
            m_type = TEXTURE;

        } else {
            LOG( ERROR ) << "Unsupported variable type " << var_type << ". Senpai fix plz\n";
        }
    }

    void shader_variable::upload_data( int data ) {
        if( m_type != INT ) {
            throw std::invalid_argument( "Cannot accept int data" );
        }

        glUniform1i( m_gl_name, data );
    }

    void shader_variable::upload_data( float data ) {
        if( m_type != FLOAT ) {
            throw std::invalid_argument( "Cannot accept float data" );
        }

        glUniform1f( m_gl_name, data );
    }

    void shader_variable::upload_data( glm::vec3 &data ) {
        if( m_type != VEC3 ) {
            throw std::invalid_argument( "Cannot accept vec3 data" );
        }

        glUniform3f( m_gl_name, data.x, data.y, data.z );
    }

    void shader_variable::upload_data( glm::vec4 &data ) {
        if( m_type != VEC4 ) {
            throw std::invalid_argument( "Cannot accept vec4 data" );
        }

        glUniform4f( m_gl_name, data.x, data.y, data.z, data.w );
    }

    void shader_variable::upload_data( glm::mat4 &data ) {
        if( m_type != MAT4 ) {
            throw std::invalid_argument( "Cannot accept mat4 data" );
        }

        glUniformMatrix4fv( m_gl_name, 1, GL_FALSE, &data[0][0] );
    }

    void shader_variable::upload_data( glm::mat3 &data ) {
        if( m_type != MAT3 ) {
            throw std::invalid_argument( "Cannot accept mat3 data" );
        }

        glUniformMatrix3fv( m_gl_name, 1, GL_FALSE, &data[0][0] );
    }

    void shader_variable::set_gl_name( GLuint gl_name ) {
        m_gl_name = gl_name;
    }

    shader_variable::type shader_variable::get_type() {
        return m_type;
    }
}
