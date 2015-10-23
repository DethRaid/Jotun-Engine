cmake_minimum_required(VERSION 3.3)
project(Jotun_Engine)

include_directories("C:\\Program Files \(x86\)\\Microsoft SDKs\\Windows\\v7.1a\\Include" "C:\\ProgramFiles \(x86\)\\Microsoft Visual Studio 14.0\\VC\\include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    glad/glad.h
    KHR/khrplatform.h
    Component.cpp
    Component.h
    easylogging++.h
    Engine.cpp
    Engine.h
    glad.c
    IPhysicsSystem.cpp
    IPhysicsSystem.h
    IRenderSystem.cpp
    IRenderSystem.h
    IScene.cpp
    IScene.h
    ISceneLoader.cpp
    ISceneLoader.h
    ISubsystem.cpp
    ISubsystem.h
    iwindow.cpp
    iwindow.h
    JsonUtils.cpp
    JsonUtils.h
    logging.conf
    main.cpp
    README.txt
    render_components.cpp
    render_components.h
    render_data.cpp
    render_data.h
    render_data_store.cpp
    render_data_store.h
    render_system_gl45.cpp
    render_system_gl45.h
    RenderableMeshScene.cpp
    RenderableMeshScene.h
    RenderableScene.cpp
    RenderableScene.h
    SampleScene.json
    SceneFileLoader.cpp
    SceneFileLoader.h
    sdl_window.cpp
    sdl_window.h
    shader_program.cpp
    shader_program.h
    shader_variables.cpp
    shader_variables.h
    stdafx.cpp
    stdafx.h
    test.frag
    Time.cpp
    Time.h
    Transform.cpp
    Transform.h
    TransformScene.cpp
    TransformScene.h)

add_executable(Jotun_Engine ${SOURCE_FILES})