#include "render_data_store.h"


namespace renderer {
    render_data_store::render_data_store() {}


    render_data_store::~render_data_store() {}

    void render_data_store::load_material( rapidjson::Value &json ) {
        m_name = json["name"].GetString();

        // Read the shaders
        std::string frag_shader_name = json["fragment_shader"].GetString();
        std::string vert_shader_name = json["vertex_shader"].GetString();

        rapidjson::Value &geom_name = json["geom_shader"];
        rapidjson::Value &tese_name = json["tese_shader"];
        rapidjson::Value &tesc_name = json["tesc_shader"];

        std::string geom_shader_name;
        std::string tese_shader_name;
        std::string tesc_shader_name;

        if( !geom_name.IsNull() ) {
            // If the geom_name exists, we can load a geometry shader
            geom_shader_name = geom_name.GetString();
        }

        if( !tese_name.IsNull() && !tesc_name.IsNull() ) {
            tese_shader_name = tese_name.GetString();
            tesc_shader_name = tesc_name.GetString();
        }

        // Read the material variables
        rapidjson::Value &variables = json["variables"];
        std::unordered_map<std::string, void*> variable_values;

        for( rapidjson::SizeType i = 0; i < variables.Size(); i++ ) {
            void* variable_value;

            if( variables[i]["type"] == "texture" ) {
                variable_value = get_gl_texture( variables[i]["value"].GetString() );
            }

            variable_values[variables[i]["name"]] = variable_value;
        }
    }
}