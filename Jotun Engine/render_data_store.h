#pragma once

#include "render_components.h"

namespace renderer {
    class render_data_store {
    public:
        render_data_store();
        ~render_data_store();

    private:
        static std::vector<renderable_mesh> m_mesh_components;
        static std::vector<light> m_lights;

        static std::vector<material> m_materials;
    };
}
