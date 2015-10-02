#pragma once
#include "stdafx.h"
#include "glad.h"
#include "shader_variables.h"

namespace Renderer {
    class shader_program {
    public:
        shader_program();
        ~shader_program();


    private:
        GLuint m_gl_name;

        // !\brief holds all the available uniform shader variable
        std::vector<shader_variable> m_variables;
    };
}
