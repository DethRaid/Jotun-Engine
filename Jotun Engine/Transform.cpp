#include "stdafx.h"
#include "Transform.h"

namespace core_services {
    transform::transform( rapidjson::Value &json ) : component( json ) {
        position = JsonUtils::loadVec3( json["position"] );
        rotation = JsonUtils::loadVec3( json["rotation"] );
        scale = JsonUtils::loadVec3( json["scale"] );
    }

    std::ostream& operator<<( std::ostream& os, const transform obj ) {
        os << "{"
            << "\"entity_id\":" <<obj.entity_id << " "
            << "\"position\":[" << obj.position.x << "," << obj.position.y << "," << obj.position.z << "],"
            << "\"rotation\":[" << obj.rotation.x << "," << obj.rotation.y << "," << obj.rotation.z << "],"
            << "\"scale\":[" << obj.scale.x << "," << obj.scale.y << "," << obj.scale.z << "]"
            << "}";
        return os;
    }
}

