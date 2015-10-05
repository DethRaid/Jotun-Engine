/*
 * Main file of the Jotun Engine excutable. This file will include code from
 * the other systems of the Jotun Engine
 */

#include <string>
#include "Engine.h"
#include "shader_program.h"

#include <glbinding/Binding.h>

int main() {
    std::string fileName = "SampleScene.json";

    //CoreServices::Engine engine;
    //engine.load_scene( fileName );

    glbinding::Binding::initialize();

    Renderer::shader_program test_prog;

    std::string shader_file_name( "test.frag" );
    test_prog.add_shader( gl::GL_FRAGMENT_SHADER, shader_file_name );

    system( "PAUSE" );
}