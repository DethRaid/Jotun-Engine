#pragma once

#include "stdafx.h"

namespace core_services {
    /*!\brief Namespace to hold engine-wide configuration

    All system-wide configuration values should be in the "config" node of the scene file
    
    Note: Be sure something calls load_config before you use any of these configuration values*/
    namespace config {
        void load_config( rapidjson::Value &json );

        extern std::string m_resource_dir;
        extern std::string m_texture_dir;
        extern std::string m_mesh_dir;
        extern std::string m_shader_dir;
    };
}
