#include "stdafx.h"
#include "SceneFileLoader.h"

namespace CoreServices {
    void SceneFileLoader::registerSceneLoader( std::string name, SceneLoaderCallback func ) {
        sceneCallbacks.emplace( name, func );
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

            std::cout << "Config: " << sceneDoc.GetType() << "\n";
            std::cout << "Loaded scene\n";

            // TODO: Assume there might be an error, maybe?
            for( auto kv : sceneCallbacks ) {
                kv.second( &sceneDoc[kv.first.c_str()] );
            }
        } else {
            std::cout << "Could not open file " << sceneFileName << "\n";
        }
    }
}
