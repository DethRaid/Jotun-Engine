#include "stdafx.h"
#include "Component.h"

namespace core_services {
    component::component( rapidjson::Value &json ) {
        entity_id = json["entity_id"].GetUint64();
    }
}
