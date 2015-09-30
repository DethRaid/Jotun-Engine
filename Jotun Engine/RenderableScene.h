#pragma once

#include "stdafx.h"

#include "IScene.h"
#include "ISceneLoader.h"

namespace Renderer {
    class RenderableScene : public CoreServices::ISceneLoader {
    public:
        RenderableScene();
        virtual ~RenderableScene();

        /* ISceneLoader methods */
        virtual void load_scene_from_json( rapidjson::Value& json );
    };
}

