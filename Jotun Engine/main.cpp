/*
 * Main file of the Jotun Engine excutable. This file will include code from
 * the other systems of the Jotun Engine
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <map>

#include "CoreServicesDLL.h"

void main() {
    std::string fileName = "../CoreServices/SampleScene.json";

    //CoreServices::SceneFileLoader loader;
    //loader.loadScene( fileName );

    CoreServices::Engine engine;
    engine.loadScene( fileName );

    system( "PAUSE" );
}