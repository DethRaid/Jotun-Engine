#include "stdafx.h"
#include "Transform.h"

namespace CoreServices {
    void Transform::loadFromJson( rapidjson::Value &json ) {
        entityId = json["entityId"].GetInt64();
        position = JsonUtils::loadVec3( json["position"] );
        rotation = JsonUtils::loadVec3( json["rotation"] );
        scale = JsonUtils::loadVec3( json["scale"] );
    }
}

