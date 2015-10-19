#include "render_components.h"

namespace renderer {
    void renderable_mesh::load_from_json( rapidjson::Value &json ) {
        entityId = json["entity_id"].GetInt64();


    }
}