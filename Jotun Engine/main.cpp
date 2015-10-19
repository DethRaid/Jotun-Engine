/*
 * Main file of the Jotun engine excutable. This file will include code from
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

    //Renderer::shader_program test_prog;

    //std::string shader_file_name( "test.frag" );
    //test_prog.add_shader( GL_FRAGMENT_SHADER, shader_file_name );

    system( "PAUSE" );
    return 0;
}