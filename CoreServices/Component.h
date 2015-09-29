#pragma once

#include "stdafx.h"

namespace CoreServices {
    class Component {
    public:
        long entityId;

        virtual void loadFromJson( rapidjson::Value &json ) = 0;
    };
}
