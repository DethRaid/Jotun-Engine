#include "shader_program.h"

namespace renderer {
    shader_program::shader_program() : linked( false ) {

    }

    shader_program::~shader_program() {}

    void shader_program::upload_variable( std::string var_name, void* var_value ) {
        shader_variable &var = m_variables[var_name];

        // The object-oriented programmer in me hates this, but I don't now of any other way to accomplish this
        switch( var.get_type() ) {
        case shader_variable::INT:
            var.upload_data( *((int*)var_value) );
            break;

        case shader_variable::FLOAT:
            var.upload_data( *((float*)var_value) );
            break;

        case shader_variable::VEC3:
            var.upload_data( *((glm::vec3*)var_value) );
            break;


        case shader_variable::VEC4:
            var.upload_data( *((glm::vec4*)var_value) );
            break;


        case shader_variable::MAT3:
            var.upload_data( *((glm::mat3*)var_value) );
            break;


        case shader_variable::MAT4:
            var.upload_data( *((glm::mat4*)var_value) );
            break;

        }
    }

    void shader_program::add_shader( GLenum shader_type, std::string& source_file_name ) {
        if( linked ) {
            throw shader_program_already_linked_exception();
        }

        GLuint shader_name = glCreateShader( shader_type );

        // Read in the shader source, getting uniforms
        std::string shader_source = read_shader_file( source_file_name );

        const char *shader_source_char = shader_source.c_str();

        glShaderSource( shader_name, 1, &shader_source_char, NULL );

        glCompileShader( shader_name );

        if( !check_for_shader_errors( shader_name ) ) {
            m_added_shaders.push_back( shader_name );
        } else {
            get_variable_locations();
        }
    }

    void shader_program::link_program() {
        linked = true;

        m_gl_name = glCreateProgram();

        for( GLuint shader : m_added_shaders ) {
            glAttachShader( m_gl_name, shader );

            if( check_for_linking_errors() ) {
                glDeleteProgram( m_gl_name );
                
                throw program_linking_failure_exception();
            }

            glDetachShader( m_gl_name, shader );
            glDeleteShader( shader );
        }

        // No errors during linking? Let's get locations for our variables
        for( auto &var : m_variables ) {
            int location = glGetUniformLocation( m_gl_name, var.first.c_str() );
            var.second.set_gl_name( location );
        }
    }

    std::string shader_program::read_shader_file( std::string& filename ) {
        // TODO: Add support for some kind of #include statement
        std::ifstream file( filename.c_str() );

        if( file.is_open() ) {
            std::string buf;
            std::string accum;
            while( getline( file, buf ) ) {
                accum += buf + "\n";

                std::string var_type;
                std::string var_name;
                std::size_t start_pos = buf.find( "uniform" );
                std::size_t end_pos = -1;

                // Parse the shader source, looking for the `uniform` keyword
                if( start_pos != std::string::npos ) {
                    // Add the length of 'uniform' and one space so we can get the type
                    start_pos += 8;
                    end_pos = buf.find( ' ', start_pos );

                    var_type = buf.substr( start_pos, end_pos - start_pos );

                    start_pos = end_pos + 1;
                    end_pos = buf.find( ';', start_pos );

                    var_name = buf.substr( start_pos, end_pos - start_pos );

                    std::cout << "Found uniform '" << var_type << "' '" << var_name << "'\n";

                    shader_variable var( var_type );
                    m_variables.emplace( var_name, var );
                }
            }
            std::cout << "Shader source: \n" << accum << "\n";
            return accum;
        }

        return std::string( "" );
    }

    bool shader_program::check_for_shader_errors( GLuint shader_to_check ) {
        GLint success = 0;

        glGetShaderiv( shader_to_check, GL_COMPILE_STATUS, &success );

        if( success == GL_FALSE ) {
            GLint log_size = 0;
            glGetShaderiv( shader_to_check, GL_INFO_LOG_LENGTH, &log_size );

            std::vector<GLchar> error_log( log_size );
            glGetShaderInfoLog( shader_to_check, log_size, &log_size, &error_log[0] );

            std::cerr << "Error compiling shader: \n" << &error_log[0] << "\n";

            glDeleteShader( shader_to_check );

            return true;
        }

        return false;
    }

    void shader_program::get_variable_locations() {

    }

    bool shader_program::check_for_linking_errors() {
        GLint is_linked = 0;
        glGetProgramiv( m_gl_name, GL_LINK_STATUS, &is_linked );

        if( is_linked == GL_FALSE ) {
            GLint log_length = 0;
            glGetProgramiv( m_gl_name, GL_INFO_LOG_LENGTH, &log_length );

            std::vector<GLchar> info_log( log_length );
            glGetProgramInfoLog( m_gl_name, log_length, &log_length, &info_log[0] );

            std::cerr << "Error linking program " << m_gl_name << ":\n" << &info_log[0] << "\n";

            return true;
        }

        return false;
    }
}
