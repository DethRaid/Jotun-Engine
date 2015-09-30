#pragma once

#include "stdafx.h"

#include "IScene.h"
#include "ISceneLoader.h"

#include "Transform.h"

namespace CoreServices {
    class TransformScene : public ISceneLoader, public Scene<Transform> {
    public:
        TransformScene();
        virtual ~TransformScene();

        /* ISceneLoader methods */
        virtual void load_scene_from_json( rapidjson::Value &json );
    };
}
