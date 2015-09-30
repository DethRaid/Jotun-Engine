#pragma once

#include "stdafx.h"

namespace CoreServices {
    /*!\brief Defines an interface for all scene loaders*/
    class ISceneLoader {
    public:
        ISceneLoader() {}
        virtual ~ISceneLoader() {}

        /*!\brief Returns the name of the node that this loader can load*/
        const std::string& get_handled_type() const;

        virtual void load_scene_from_json( rapidjson::Value &json ) = 0;

    protected:
        std::string m_handled_type;
    };
}
