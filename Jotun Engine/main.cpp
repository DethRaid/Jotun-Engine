/*
 * Main file of the Jotun Engine excutable. This file will include code from
 * the other systems of the Jotun Engine
 */

#include <string>
#include "Engine.h"

void main() {
    std::string fileName = "SampleScene.json";

    CoreServices::Engine engine;
    engine.load_scene( fileName );

    system( "PAUSE" );
}