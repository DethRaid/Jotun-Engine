#pragma once
#include "stdafx.h"
#include <exception>

namespace renderer {
    class shader_variable {
    public:
        enum type {
            INT,
            FLOAT,
            VEC3,
            VEC4,
            MAT3,
            MAT4,
            TEXTURE,
        };

        // Added so tuples won't yell at me
        shader_variable() {}
        shader_variable( std::string var_type );

        void upload_data( int data );
        void upload_data( float data );
        void upload_data( glm::vec3 &data );
        void upload_data( glm::vec4 &data );
        void upload_data( glm::mat3 &data );
        void upload_data( glm::mat4 &data );

        // TODO: method for uploading textures

        void set_gl_name( GLuint gl_name );
        type get_type();
    protected:
        GLuint m_gl_name;
        type m_type;
    };

    
}
