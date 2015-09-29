#include "stdafx.h"
#include "TransformScene.h"

namespace CoreServices {
    TransformScene::TransformScene() {}

    TransformScene::~TransformScene() {}

    std::string TransformScene::get_handled_type() {
        return "transform";
    }

    void TransformScene::load_scene_from_json( rapidjson::Value &json ) {

    }

    const std::vector<Transform> &TransformScene::getComponents() const {
        return transforms;
    }
}