#include "render_components.h"

namespace renderer {
    void renderable_mesh::load_from_json( rapidjson::Value &json ) {
        entity_id = json["entity_id"].GetInt64();


    }
}