#include "render_data_store.h"
#include "config.h"

namespace renderer {
    render_data_store::render_data_store() {}


    render_data_store::~render_data_store() {}

    void render_data_store::load_material( rapidjson::Value &json ) {
        std::string material_name = json["name"].GetString();

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

            variable_values[variables[i]["name"].GetString()] = variable_value;
        }
    }

    void render_data_store::load_shader( rapidjson::Value &json ) {
        static std::string shader_dir = core_services::config::m_resource_dir + core_services::config::m_shader_dir;
        shader_program new_program;

        std::string shader_program_name = json["name"].GetString();

        std::string vert_file_name = shader_dir + json["vert_shader"].GetString();
        std::string frag_file_name = shader_dir + json["frag_shader"].GetString();

        new_program.add_shader( GL_VERTEX_SHADER, vert_file_name );
        new_program.add_shader( GL_FRAGMENT_SHADER, frag_file_name );

        rapidjson::Value &geom_name = json["geom_shader"];
        if( !geom_name.IsNull() ) {
            std::string geom_file_name = shader_dir + geom_name.GetString();
            new_program.add_shader( GL_GEOMETRY_SHADER, geom_file_name );
        }

        rapidjson::Value &tese_name = json["tese_shader"];
        rapidjson::Value &tesc_name = json["tesc_shader"];
        if( !tesc_name.IsNull() && !tese_name.IsNull() ) {
            std::string tese_file_name = tese_name.GetString();
            std::string tesc_file_name = tesc_name.GetString();

            new_program.add_shader( GL_TESS_CONTROL_SHADER, tesc_file_name );
            new_program.add_shader( GL_TESS_EVALUATION_SHADER, tese_file_name );
        }

        new_program.link_program();
    }
}