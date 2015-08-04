#include "stdafx.h"
#include "TransformScene.h"

namespace CoreServices {
    TransformScene::TransformScene() {}

    TransformScene::~TransformScene() {}

    void TransformScene::registerSelf( SceneFileLoader *loader ) {
        loader->registerSceneLoader( "transform", this );
    }

    void TransformScene::loadSceneFromJson( rapidjson::Value &json ) {

    }

    const std::vector<Transform> &TransformScene::getComponents() const {
        return transforms;
    }
}