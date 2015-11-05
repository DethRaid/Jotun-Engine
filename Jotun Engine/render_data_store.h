#pragma once

#include "render_data.h"
#include "render_components.h"

namespace renderer {
    class render_data_store {
    public:
        render_data_store();
        ~render_data_store();

        GLint * get_gl_texture( const std::string &name );

        /* Methods for shaders */
        shader_program get_program_with_shaders( std::string &vert_name, std::string &frag_name );
        shader_program get_program_with_shaders( std::string &vert_name, std::string &frag_name, std::string &geom_name );
        shader_program get_program_with_shaders( std::string &vert_name, std::string &frag_name, std::string &tese_name, std::string &tesc_name );
        shader_program get_program_with_shaders( std::string &vert_name, std::string &frag_name, std::string &geom_name, std::string &tese_name, std::string &tesc_name );

        //TODO: Write a much of methods to handle loading loading each data type, and figure out how to pass them around
    private:
        std::vector<renderable_mesh> m_mesh_components;
        std::vector<light> m_lights;

        /*!\brief A map from string name to material */
        std::unordered_map<std::string, material> m_materials;
        std::unordered_map<std::string, texture> m_textures;
        std::unordered_map<std::string, shader_program> m_shaders;

        /* Simple load their data from the provided JSON object */
        void load_material( rapidjson::Value &json );
        void load_shader( rapidjson::Value &json );

        /* Aquire the JSON object */
    };
}
