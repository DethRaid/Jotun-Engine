#include "stdafx.h"
#include "TransformScene.h"

namespace core_services {
    TransformScene::TransformScene() {
        m_handled_type = "transform";
    }

    TransformScene::~TransformScene() {}

    void TransformScene::load_scene_from_json( rapidjson::Value &json ) {
        rapidjson::Value& values = json["values"];

        for( auto itr = values.Begin(); itr != values.End(); ++itr ) {
            Transform newTransform;
            newTransform.load_from_json( *itr );
            components.push_back( newTransform );
            std::cout << "Loaded new transform " << newTransform << "\n";
        }
    }
}