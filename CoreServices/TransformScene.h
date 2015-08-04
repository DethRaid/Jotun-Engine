#pragma once

#include "IScene.h"
#include "ISceneLoader.h"

#include "SceneFileLoader.h"
#include "Transform.h"

namespace CoreServices {
    class TransformScene : ISceneLoader, IScene<Transform> {
    public:
        TransformScene();
        ~TransformScene();

        /* ISceneLoader methods */
        void registerSelf( SceneFileLoader *loader );
        void loadSceneFromJson( rapidjson::Value &json );

        /* IScene methods */
        const std::vector<Transform> & getComponents() const;
    private:
        std::vector<Transform> transforms;
    };

    void loadTransformSceneFromJson( rapidjson::Value &json, ISceneLoader *loader );
}
