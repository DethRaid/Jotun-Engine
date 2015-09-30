#pragma once

#include "stdafx.h"

namespace CoreServices {
    class Component {
    public:
        long entityId;

        virtual void load_from_json( rapidjson::Value &json ) = 0;
    };
}
