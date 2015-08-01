#include "stdafx.h"
#include "SceneLoader.h"

namespace CoreServices {
    void SceneLoader::loadScene( std::string &sceneFileName ) {
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

            for( auto kv : sceneCallbacks ) {
                kv.second( &sceneDoc[kv.first.c_str()] );
            }
        } else {
            std::cout << "Could not open file " << sceneFileName << "\n";
        }
    }
}
