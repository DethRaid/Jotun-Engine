/*
 * Main file of the Jotun engine executable. This file will include code from
 * the other systems of the Jotun engine
 */

#include <string>
#include "engine.h"
#include "shader_program.h"

INITIALIZE_EASYLOGGINGPP

int main( int argc, char *argv[] ) {
    std::string fileName = "SampleScene.json";

    core_services::engine engine;
    engine.load_scene( fileName );

    system( "PAUSE" );
    return 0;
}