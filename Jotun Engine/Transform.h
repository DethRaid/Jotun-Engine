#pragma once

#include "stdafx.h"

#include "Component.h"
#include "JsonUtils.h"

namespace CoreServices {
    class Transform : public component {
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;

        virtual void load_from_json( rapidjson::Value &json );
    };

    std::ostream& operator<<( std::ostream& os, const Transform obj );
}
