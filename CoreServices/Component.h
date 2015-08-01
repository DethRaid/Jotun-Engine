#pragma once

#include <rapidjson\document.h>

namespace CoreServices {
    class Component {
    public:
        long entityId;

        virtual void loadFromJson( rapidjson::Value &json ) = 0;
    };
}
