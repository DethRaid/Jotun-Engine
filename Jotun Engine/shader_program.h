#pragma once
#include "stdafx.h"
#include "shader_variables.h"

#include <exception>
#include <fstream>

namespace renderer {
    class shader_program_already_linked_exception : public std::exception {};

    class shader_program {
    public:
        shader_program();
        ~shader_program();

        /*!\brief Sends the given value to the uniform variable with the given name, uploading that data to the GPU

        If you want super duper performant code, call this method as seldom as possible*/
        void upload_variable( std::string var_name, void* var_value );

        /*!\brief Adds a shader to this program, does not compile the program*/
        void add_shader( GLenum shader_type, std::string& source_file_name );

        /*!\brief Links this program

        This method should be called after you've added all your shaders.
        Adding a shader after linking will get you a nice
        shader_program_already_linked_exception*/
        void link_program();

    private:
        GLuint m_gl_name;

        // !\brief holds all the available uniform shader variable
        std::unordered_map<std::string, shader_variable*> m_variables;

        bool linked;

        std::string read_shader_file( std::string& filename );
    };
}
