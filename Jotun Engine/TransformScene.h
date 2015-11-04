#pragma once

#include "stdafx.h"

#include "IScene.h"
#include "Transform.h"
#include "component_loader.h"

namespace core_services {
    class transform_scene : public scene<transform>, public component_loader {
    public:
        transform_scene();
        virtual ~transform_scene();

    protected:
        virtual void load_one_component( rapidjson::Value &json );
    };
}
