#include "stdafx.h"
#include "SceneFileLoader.h"
#include "config.h"

namespace core_services {
    SceneFileLoader::SceneFileLoader() {}

    SceneFileLoader::~SceneFileLoader() {}

    void SceneFileLoader::register_component_loader( component_loader *loader ) {
        sceneCallbacks.emplace( loader->get_handled_type(), loader );

        LOG( INFO ) << "Registered loader for component type " << loader->get_handled_type() << "\n";
    }

    void SceneFileLoader::register_data_loader( std::string data_name, data_loader *loader ) {
        m_data_loaders.emplace( data_name, loader );

        LOG( INFO ) << "Registered loader for data type " << data_name << "\n";
    }

    void SceneFileLoader::loadScene( std::string &sceneFileName ) {
        LOG( INFO ) << "Loading scene " <<sceneFileName.c_str() <<"\n";

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

            LOG( INFO ) << "Loaded scene\n";

            // TODO: Assume there might be an error, maybe?
            for( auto kv : sceneCallbacks ) {
                LOG( TRACE ) << "Loading data for component " << kv.first << "\n";
                try {
                    kv.second->load_from_json( sceneDoc[kv.first.c_str()]["values"] );
                } catch( std::exception &e ) {
                    LOG( ERROR ) << "Exception occured :" << e.what() << "\n";
                }
            }

            for( auto kv : m_data_loaders ) {
                LOG( TRACE ) << "Loading data for type " << kv.first << "\n";
                try {
                    kv.second->load_data( sceneDoc[kv.first.c_str()] );
                } catch( std::exception &e ) {
                    LOG( ERROR ) << "Exception occured :" <<e.what() <<"\n";
                }
            }
        } else {
            LOG( ERROR ) << "Could not open file " << sceneFileName << "\n";
        }
    }
}
