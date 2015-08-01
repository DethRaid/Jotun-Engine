#pragma once

#include "CoreServicesDLL.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include <rapidjson\rapidjson.h>
#include <rapidjson\document.h>

namespace CoreServices {
    typedef void( *SceneLoaderCallback )(rapidjson::Value*);

    class SceneFileLoader {
    public:
        /*!\brief Allows the user to register a function to call to load data from a specific JSON node
         *
         * Loader functions have a void return type and take a single parameter, a rapidjson::Document*
         */
        CORESERVICESDLL_API void registerSceneLoader( std::string name, SceneLoaderCallback func );

        /*!\brief Loads the scene file with the given filename, calling the appropriate loader function
        
        This methos should be called after all scene loaders are registered
        */
        CORESERVICESDLL_API void loadScene( std::string &sceneFileName);
    private:
        rapidjson::Document sceneDoc;
        std::unordered_map<std::string, SceneLoaderCallback> sceneCallbacks;
    };
}
