#pragma once

#include "stdafx.h"

#include "component_loader.h"

namespace core_services {

    class SceneFileLoader {
    public:
        SceneFileLoader();
        ~SceneFileLoader();
        /*!\brief Allows the user to register a function to call to load data from a specific JSON node
         *
         * Loader functions have a void return type and take a single parameter, a rapidjson::Document*
         */
        void register_scene_loader( component_loader *loader );

        /*!\brief Loads the scene file with the given filename, calling the appropriate loader function
        
        This methos should be called after all scene loaders are registered
        */
        void loadScene( std::string &sceneFileName );
    private:
        rapidjson::Document sceneDoc;
        std::unordered_map<std::string, component_loader*> sceneCallbacks;
    };
}
