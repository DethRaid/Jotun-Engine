#pragma once

#include "stdafx.h"

#include "glad.h"
#include "Component.h"

namespace Renderer {
    struct renderable_mesh : CoreServices::component {
        long m_material_id;
        long m_mesh_id;
    };

    struct light : CoreServices::component {
        enum type {
            kDirectional,
            kPoint,
            kSpot,
        };

        type m_light_type;
        glm::vec3 m_color;
        bool m_cast_shadow;
        float m_strength;
    };

    struct shader {
        GLuint m_gl_name;
        std::string m_name;
    };

    struct vertex_shader : shader {
        std::unordered_map<std::string, GLuint> m_in_vars;
    };

    struct fragment_shader : shader {
        std::unordered_map<std::string, GLuint> m_uniform_vars;
    };

    struct tese_shader : shader {};
    struct tesc_shader : shader {};
    struct geom_shader : shader {};

    struct material {
        long m_id;
        std::string m_name;
        vertex_shader* m_vertex_shader;
        fragment_shader* m_fragment_shader;
        tesc_shader* m_tesc_shader;
        tese_shader* m_tese_shader;
        geom_shader* m_geom_shader;
        
        GLuint m_program_name;

        std::unordered_map<std::string, GLuint> m_texture_map;

        void compile_program() {

        }
    };
}
