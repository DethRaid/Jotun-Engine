#include "shader_program.h"

namespace renderer {
    shader_program::shader_program() : linked( false ) {

    }

    shader_program::~shader_program() {}

    void shader_program::upload_variable( std::string var_name, void* var_value ) {
        shader_variable *var = m_variables[var_name];

        // The object-oriented programmer in me hates this, but I don't now of any other way to accomplish this
        switch( var->get_type() ) {
        case shader_variable::INT:
            var->upload_data( *((int*)var_value) );
            break;

        case shader_variable::FLOAT:
            var->upload_data( *((float*)var_value) );
            break;

        case shader_variable::VEC3:
            var->upload_data( *((glm::vec3*)var_value) );
            break;


        case shader_variable::VEC4:
            var->upload_data( *((glm::vec4*)var_value) );
            break;


        case shader_variable::MAT3:
            var->upload_data( *((glm::mat3*)var_value) );
            break;


        case shader_variable::MAT4:
            var->upload_data( *((glm::mat4*)var_value) );
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

                    if( var_type == "int" ) {
                        break;
                    } else {
                        std::cerr << "Unsupported variable type " << var_type << ". Senpai plz fix\n";
                    }
                }
            }
            std::cout << "Shader source: \n" << accum << "\n";
            return accum;
        }

        return std::string( "" );
    }
}
