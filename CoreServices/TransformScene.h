#pragma once

#include "stdafx.h"

#include "IScene.h"
#include "ISceneLoader.h"

#include "SceneFileLoader.h"
#include "Transform.h"

namespace CoreServices {
    class TransformScene : public ISceneLoader, public IScene<Transform> {
    public:
        TransformScene();
        virtual ~TransformScene();

        /* ISceneLoader methods */
        virtual std::string get_handled_type();
        virtual void load_scene_from_json( rapidjson::Value &json );

        /* IScene methods */
        virtual const std::vector<Transform> & getComponents() const;
    private:
        std::vector<Transform> transforms;
    };
}
