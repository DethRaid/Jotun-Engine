#include "render_components.h"

namespace renderer {
    void renderable_mesh::load_from_json( rapidjson::Value &json ) {
        entity_id = json["entity_id"].GetInt64();

        std::string mesh_file_name = json["filename"].GetString();

        // Request the mesh with this name from the mesh store

        std::string material_name = json["material"].GetString();

        // Request the material with this name from the material store

        // If a mesh or material isn't available, it should be loaded immediately and saved for future use
    }
}