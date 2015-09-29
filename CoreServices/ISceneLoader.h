#pragma once

#include "stdafx.h"

namespace CoreServices {
    /*!\brief Defines an interface for all scene loaders*/
    class ISceneLoader {
    public:
        ISceneLoader() {}
        virtual ~ISceneLoader() {}

        /*!\brief Returns the name of the node that this loader can load*/
        virtual std::string get_handled_type() = 0;

        virtual void load_scene_from_json( rapidjson::Value &json ) = 0;
    };
}
