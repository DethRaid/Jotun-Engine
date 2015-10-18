#pragma once

#include "stdafx.h"

namespace core_services {
    class component {
    public:
        long entityId;

        //!\brief primary key
        long id;

        virtual void load_from_json( rapidjson::Value &json ) = 0;
    };
}
