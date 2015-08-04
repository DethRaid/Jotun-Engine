#pragma once

#include "SceneFileLoader.h"

namespace CoreServices {
    class CORESERVICESDLL_API SceneFileLoader;

    /*!\brief Defines an interface for all scene loaders*/
    class CORESERVICESDLL_API ISceneLoader {
    public:
        virtual void registerSelf( SceneFileLoader *loader ) = 0;
        virtual void loadSceneFromJson( rapidjson::Value &json ) = 0;
    };
}
