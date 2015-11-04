#pragma once

#include "render_data.h"
#include "render_components.h"
#include "material_loader.h"

namespace renderer {
    class render_data_store {
    public:
        render_data_store();
        ~render_data_store();

        GLint * get_gl_texture( const std::string &name );

        //TODO: Write a much of methods to handle loading loading each data type, and figure out how to pass them around
    private:
        material_loader m_mat_loader;

        std::vector<renderable_mesh> m_mesh_components;
        std::vector<light> m_lights;

        /*!\brief A map from string name to material */
        std::unordered_map<std::string, material> m_materials;
        std::unordered_map<std::string, texture> m_textures;

        void load_material( rapidjson::Value &json );
    };
}
