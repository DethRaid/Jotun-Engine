#include "config.h"

namespace core_services {
    namespace config {
        std::string m_resource_dir;
        std::string m_texture_dir;
        std::string m_mesh_dir;
        std::string m_shader_dir;

        void load_config( rapidjson::Value &json ) {
            m_resource_dir = json["resource_dir"].GetString();
            m_texture_dir = json["texture_dir"].GetString();
            m_mesh_dir = json["mesh_dir"].GetString();
            m_shader_dir = json["shader_dir"].GetString();
        }
    }
}