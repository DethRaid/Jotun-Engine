#pragma once

#include "stdafx.h"

#include "Component.h"

namespace renderer {
    class renderable_mesh : core_services::component {
    public:
        long m_material_id;
        long m_mesh_id;

        virtual void load_from_json( rapidjson::Value &json );
    };

    class light : core_services::component {
    public:
        enum type {
            kDirectional,
            kPoint,
            kSpot,
        };

        type m_light_type;
        glm::vec3 m_color;
        bool m_cast_shadow;
        float m_strength;

        virtual void load_from_json( rapidjson::Value &json );
    };
}
