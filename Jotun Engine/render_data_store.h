#pragma once

#include "render_data.h"
#include "render_components.h"
#include "data_loader.h"

namespace renderer {
    /*!\brief Loads all the render data
    
    The Render Data is all stored in the render_data object in the scene file json. This class handles all the data ni that object*/
    class render_data_store : public core_services::data_loader {
    public:
        render_data_store();
        ~render_data_store();

        GLuint get_gl_texture( const std::string &name );

        shader_program get_shader_program( const std::string &name );

        /* Overriden from data_loader */
        virtual void load_data( rapidjson::Value &json );

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
