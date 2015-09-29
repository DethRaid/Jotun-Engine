#pragma once

#include "stdafx.h"

#include "ISceneLoader.h"

namespace CoreServices {
    class SceneFileLoader {
    public:
        SceneFileLoader();
        ~SceneFileLoader();
        /*!\brief Allows the user to register a function to call to load data from a specific JSON node
         *
         * Loader functions have a void return type and take a single parameter, a rapidjson::Document*
         */
        void register_scene_loader( ISceneLoader *loader );

        /*!\brief Loads the scene file with the given filename, calling the appropriate loader function
        
        This methos should be called after all scene loaders are registered
        */
        void loadScene( std::string &sceneFileName );
    private:
        rapidjson::Document sceneDoc;
        std::unordered_map<std::string, ISceneLoader*> sceneCallbacks;
    };
}
