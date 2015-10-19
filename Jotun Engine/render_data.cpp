#include "render_data.h"

namespace renderer {
    material::material( std::string& name ) :
        m_name( name ) {}

    material::~material() {}

    void material::set_shader_program( shader_program* new_shader_program ) {
        m_shader_program = new_shader_program;
    }

    void material::upload_values() {
        for( auto itr = m_variable_values.begin(); itr != m_variable_values.end(); ++itr ) {
            m_shader_program->upload_variable( itr->first, itr->second );
        }
    }

    void material::upload_variable( std::string& var_name, void* var_data ) {
        m_variable_values.emplace( var_name, var_data );
    }
}