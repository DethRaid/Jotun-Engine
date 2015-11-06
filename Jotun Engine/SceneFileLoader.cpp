#include "stdafx.h"
#include "SceneFileLoader.h"
#include "config.h"

namespace core_services {
    SceneFileLoader::SceneFileLoader() {}

    SceneFileLoader::~SceneFileLoader() {}

    void SceneFileLoader::register_component_loader( component_loader *loader ) {
        sceneCallbacks.emplace( loader->get_handled_type(), loader );
    }

    void SceneFileLoader::register_data_loader( std::string data_name, data_loader *loader ) {
        m_data_loaders.emplace( data_name, loader );
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

            config::load_config( sceneDoc["config"] );

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
