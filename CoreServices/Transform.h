#pragma once

#include "stdafx.h"

#include "Component.h"
#include "JsonUtils.h"

namespace CoreServices {
    class Transform : public Component {
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;

        void loadFromJson( rapidjson::Value &json );
    };

}
