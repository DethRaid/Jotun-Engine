#pragma once

#include "stdafx.h"

#include "Component.h"
#include "JsonUtils.h"

namespace core_services {
    class transform : public component {
    public:
        transform( rapidjson::Value &json );

        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
    };

    std::ostream& operator<<( std::ostream& os, const transform obj );
}
