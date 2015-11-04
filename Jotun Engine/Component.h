#pragma once

#include "stdafx.h"

namespace core_services {
    class component {
    public:
        component( rapidjson::Value &json );

        long entity_id;

        //!\brief primary key
        long id;
    };
}
