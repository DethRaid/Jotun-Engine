#include "render_data.h"

namespace renderer {
    material::material( std::string& name, shader_program* program ) :
        m_name( name ) {
        m_shader_program = program;
    }

    material::~material() {}

    void material::set_shader_program( shader_program* new_shader_program ) {
        m_shader_program = new_shader_program;
    }

    void material::upload_values() {
        for( auto itr = m_variable_values.begin(); itr != m_variable_values.end(); ++itr ) {
            m_shader_program->upload_variable( itr->first, itr->second );
        }
    }

    void material::set_variable( std::string& var_name, void* var_data ) {
        if( m_variable_values.find( var_name ) == m_variable_values.end() ) {
            // There's nothing named var_name in the map yet
            m_variable_order.push_back( var_name );
        }
        m_variable_values[var_name] = var_data;
    }
}