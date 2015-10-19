#include "stdafx.h"
#include "Transform.h"

namespace core_services {
    void Transform::load_from_json( rapidjson::Value &json ) {
        entityId = json["entity_id"].GetInt64();
        position = JsonUtils::loadVec3( json["position"] );
        rotation = JsonUtils::loadVec3( json["rotation"] );
        scale = JsonUtils::loadVec3( json["scale"] );
    }

    std::ostream& operator<<( std::ostream& os, const Transform obj ) {
        os << "{"
            << "\"entity_id\":" <<obj.entityId << " "
            << "\"position\":[" << obj.position.x << "," << obj.position.y << "," << obj.position.z << "],"
            << "\"rotation\":[" << obj.rotation.x << "," << obj.rotation.y << "," << obj.rotation.z << "],"
            << "\"scale\":[" << obj.scale.x << "," << obj.scale.y << "," << obj.scale.z << "]"
            << "}";
        return os;
    }
}

