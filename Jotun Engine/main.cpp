/*
 * Main file of the Jotun engine executable. This file will include code from
 * the other systems of the Jotun engine
 */

#include "stdafx.h"
#include "Engine.h"

INITIALIZE_EASYLOGGINGPP

int main( int argc, char *argv[] ) {
    // Configure the logger
    el::Configurations conf( "logging.conf" );

    // Turn debug and trace off in release builds
#ifndef NDEBUG
    conf.parseFromText( "*DEBUG:\n ENABLED=false" );
#endif

    el::Loggers::reconfigureAllLoggers( conf );

    std::string fileName = "SampleScene.json";

    core_services::engine engine;
    engine.load_scene( fileName );

    system( "PAUSE" );
    return 0;
}