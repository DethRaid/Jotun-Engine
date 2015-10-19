#pragma once

#include "stdafx.h"
#include "shader_program.h"

namespace renderer {
    class material {
    public:
        material( std::string& name );
        ~material();

        /*!\brief Sets the shader program that this material will use for rendering*/
        void set_shader_program( shader_program* new_shader_program );

        /*!\brief Sends all the set values to the GPU*/
        void upload_values();

        /*!\brief Sets a variable in CPU memory, but does not upload it to the GPU*/
        void upload_variable( std::string& var_name, void* var_data );

    private:
        long m_id;
        std::string m_name;
        shader_program* m_shader_program;

        std::unordered_map<std::string, void*> m_variable_values;
    };
}
