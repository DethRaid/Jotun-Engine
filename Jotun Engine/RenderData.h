#pragma once

#include "stdafx.h"

#include <glbinding/gl/gl.h>
#include "Component.h"

namespace Renderer {
    struct renderable_mesh : CoreServices::component {
        long m_material_id;
        long m_mesh_id;
    };

    struct light : CoreServices::component {
        enum type {
            kDirectional,
            kPoint,
            kSpot,
        };

        type m_light_type;
        glm::vec3 m_color;
        bool m_cast_shadow;
        float m_strength;
    };
}
