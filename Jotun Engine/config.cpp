#include "config.h"

namespace core_services {
    namespace config {
        void load_config( rapidjson::Value &json ) {
            m_resource_dir = json["resource_dir"].GetString();
            m_texture_dir = json["tex_dir"].GetString();
            m_mesh_dir = json["mesh_dir"].GetString();
            m_shader_dir = json["shader_dir"].GetString();
        }
    }
}