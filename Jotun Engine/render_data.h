#pragma once

#include "stdafx.h"
#include "shader_program.h"

namespace renderer {
    /*!\brief Represents a single mesh in the scene

    Note that all static meshes are stored in a sinble VBO. Thus, a \class mesh
    is really just a pointer to the place in that VBO where it's stored
    */
    class mesh {
    private:
        std::string m_name;
        unsigned int m_start_index;
        unsigned int m_num_elements;
    };

    class material {
    public:
        material( std::string& name, shader_program *program );
        ~material();

        /*!\brief Sets the shader program that this material will use for rendering*/
        void set_shader_program( shader_program* new_shader_program );

        /*!\brief Sends all the set values to the GPU*/
        void upload_values();

        /*!\brief Sets a variable in CPU memory, but does not upload it to the GPU*/
        void set_variable( std::string& var_name, void* var_data );

        const std::string get_name();

    private:
        long m_id;
        std::string m_name;
        shader_program* m_shader_program;

        std::vector<std::string> m_variable_order;
        std::unordered_map<std::string, void*> m_variable_values;
    };

    class texture {
        // TODO: Implement this class
    public:
        GLint get_gl_name();
    private:
        GLint m_gl_name;
    };
}
