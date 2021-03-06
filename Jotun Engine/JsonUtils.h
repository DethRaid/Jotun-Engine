#pragma once

#include <rapidjson/document.h>
#include <gl/glm/common.hpp>

namespace core_services {
    namespace JsonUtils {
        glm::vec3 loadVec3( rapidjson::Value &value );
    }
}