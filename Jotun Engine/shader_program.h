#pragma once
#include "stdafx.h"
#include "shader_variables.h"

#include <exception>
#include <fstream>

namespace renderer {
    class shader_program_already_linked_exception : public std::exception {};
    class program_linking_failure_exception : public std::exception {};

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
        std::unordered_map<std::string, shader_variable> m_variables;

        /*!\brief Holds the type of added shaders in the keys and the OpenGL name of the added shaders in the value.
        
        Shaders are only added if they've been successfully compiled. They can be added through the add_shader() method*/
        std::vector<GLuint> m_added_shaders;

        bool linked;

        std::string read_shader_file( std::string& filename );

        /*!\brief Checks for compilation errors for the given shader
        
        \return False if the compilation succeeded, true otherwise*/
        bool check_for_shader_errors( GLuint shader_to_check );

        /*!\brief Goes through every shader_variable stored in m_variables, getting the OpenGL location of each one*/
        void get_variable_locations();

        bool check_for_linking_errors();
    };
}
