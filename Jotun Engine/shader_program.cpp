#include "shader_program.h"

namespace renderer {
    shader_program::shader_program() : linked( false )
    {

    }

    shader_program::~shader_program() {}

    void shader_program::upload_variable( std::string var_name, void* var_value ) {
        m_variables[var_name]->upload_data( var_value );
    }

    void shader_program::add_shader( GLenum shader_type, std::string& source_file_name ) {
        if( linked ) {
            throw shader_program_already_linked_exception();
        }

        GLuint shader_name = glCreateShader( shader_type );

        // Read in the shader source, getting uniforms
        std::string shader_source = read_shader_file( source_file_name );
    }

    void shader_program::link_program() {
        linked = true;
    }

    std::string shader_program::read_shader_file( std::string& filename ) {
        std::ifstream file( filename.c_str() );

        if( file.is_open() ) {
            std::string buf;
            std::string accum;
            while( getline( file, buf ) ) {
                accum += buf;
            }

            std::string var_type;
            std::string var_name;
            std::size_t start_pos = accum.find( "uniform" );
            std::size_t end_pos = -1;

            // Parse the shader source, looking for the `uniform` keyword
            while( start_pos != std::string::npos ) {
                // Add the length of 'uniform' and one space so we can get the type
                start_pos += 8;
                end_pos = accum.find( ' ', start_pos );

                var_type = accum.substr( start_pos, end_pos - start_pos );

                start_pos = end_pos;
                end_pos = accum.find( ';', start_pos );

                var_name = accum.substr( start_pos, end_pos - start_pos );

                std::cout << "Found uniform '" << var_type << " " << var_name << "'\n";
            }
            return accum;
        }

        return std::string( "" );
    }
}
