#pragma once

#include "stdafx.h"
#include "component_loader.h"
#include "render_data.h"

namespace renderer {
    class material_loader : public core_services::component_loader {
    public:
        material_loader( std::unordered_map<std::string, material> *data_destination );
        ~material_loader();

    protected:
        virtual void load_one_component( rapidjson::Value &json );

    private:
        std::unordered_map<std::string, material> *m_data_destination
    };
}

