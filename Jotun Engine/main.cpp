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

    CoreServices::SceneLoader loader;
    loader.init();
    loader.loadScene( fileName );
    loader.deinit();

    system( "PAUSE" );
}