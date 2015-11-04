#include "stdafx.h"
#include "SceneFileLoader.h"

namespace core_services {
    SceneFileLoader::SceneFileLoader() {}

    SceneFileLoader::~SceneFileLoader() {}

    void SceneFileLoader::register_scene_loader( component_loader *loader ) {
        sceneCallbacks.emplace( loader->get_handled_type(), loader );
    }

    void SceneFileLoader::loadScene( std::string &sceneFileName ) {
        std::cout << "Loading scene " <<sceneFileName.c_str() <<"\n";

        std::ifstream fileStream( sceneFileName.c_str() );
        std::string buf;
        std::string accum;
       
        // TODO: Improve scene loader speed by using a fancier file reading thing
        if( fileStream.is_open() ) {
            while( getline( fileStream, buf ) ) {
                accum += buf;
            }
            sceneDoc.Parse( accum.c_str() );

            std::cout << "Config: " << sceneDoc["config"]["resource_dir"].GetString() << "\n";

            std::cout << "Loaded scene\n";

            // TODO: Assume there might be an error, maybe?
            for( auto kv : sceneCallbacks ) {
                std::cout << "Loading data for type " << kv.first << "\n";
                try {
                    kv.second->load_from_json( sceneDoc[kv.first.c_str()]["values"] );
                } catch( ... ) {
                    std::cout << "Exception occured :(\n";
                }
            }
        } else {
            std::cout << "Could not open file " << sceneFileName << "\n";
        }
    }
}
