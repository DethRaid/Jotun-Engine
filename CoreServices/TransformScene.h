#pragma once

#include "IScene.h"
#include "ISceneLoader.h"

#include "Transform.h"

namespace CoreServices {
    class TransformScene : ISceneLoader, IScene<Transform> {
    public:
        TransformScene();
        ~TransformScene();

        void loadSceneFromJson( rapidjson::Value &json );
        std::vector<Transform> getComponents();
    private:
        std::vector<Transform> transforms;
    };
}
