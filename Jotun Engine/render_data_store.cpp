#include "render_data_store.h"
#include "config.h"

namespace renderer {
    render_data_store::render_data_store() {}


    render_data_store::~render_data_store() {}

    GLuint render_data_store::get_gl_texture( const std::string &name ) {
        return m_textures[name].get_gl_name();
    }

    void render_data_store::load_data( rapidjson::Value &json ) {
        rapidjson::Value &materials = json["material"]["values"];

        for( auto itr = materials.Begin(); itr != materials.End(); ++itr ) {
            load_material( *itr );
        }

        rapidjson::Value &shader_programs = json["shader_program"]["values"];

        for( auto itr = shader_programs.Begin(); itr != shader_programs.End(); ++itr ) {
            try {
                load_shader( *itr );
            } catch( std::exception &e ) {
                LOG( ERROR ) << "An exception occured: " << e.what();
            }
        }
    }

    void render_data_store::load_material( rapidjson::Value &json ) {
        std::string material_name = json["name"].GetString();
        
        // Read the material variables
        rapidjson::Value &variables = json["variables"];
        std::unordered_map<std::string, void*> variable_values;

        for( rapidjson::SizeType i = 0; i < variables.Size(); i++ ) {
            void* variable_value = NULL;

            if( variables[i]["type"] == "texture" ) {
                variable_value = new GLuint( get_gl_texture( variables[i]["value"].GetString() ) );
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

        if( json.HasMember( "geom_shader" ) ) {
            std::string geom_file_name = shader_dir + json["geom_shader"].GetString();
            new_program.add_shader( GL_GEOMETRY_SHADER, geom_file_name );
        }
        

        auto tese_name_itr = json.FindMember( "tese_shader" );
        auto tesc_name_itr = json.FindMember( "tecs_shader" );
        if( tese_name_itr != json.MemberEnd() && tesc_name_itr != json.MemberEnd() ) {
            std::string tese_file_name = shader_dir + json["tese_shader"].GetString();
            std::string tesc_file_name = shader_dir + json["tesc_shader"].GetString();

            new_program.add_shader( GL_TESS_CONTROL_SHADER, tesc_file_name );
            new_program.add_shader( GL_TESS_EVALUATION_SHADER, tese_file_name );
        }

        new_program.link_program();

        m_shaders.emplace( shader_program_name, new_program );
    }
}