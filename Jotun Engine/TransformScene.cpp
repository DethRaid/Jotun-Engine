#include "stdafx.h"
#include "TransformScene.h"

namespace core_services {
    transform_scene::transform_scene() {
        m_handled_type = "transform";
    }

    transform_scene::~transform_scene() {}

    void transform_scene::load_one_component( rapidjson::Value &json ) {
        transform new_transform( json );
        m_components.push_back( new_transform );
    }
}