#include "material_loader.h"

namespace renderer {
    material_loader::material_loader( std::unordered_map<std::string, material> *data_destination ) {
        m_handled_type = "material";
        m_data_destination = data_destination;
    }

    material_loader::~material_loader() {}

    void material_loader::load_one_component( rapidjson::Value &json ) {
        material mat( json );
        m_data_destination->emplace( mat.get_name(), mat );
    }
}
