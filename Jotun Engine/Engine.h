#pragma once

#include "stdafx.h"

#include "Time.h"
#include "TransformScene.h"
#include "SceneFileLoader.h"
#include "IPhysicsSystem.h"
#include "ISubsystem.h"
#include "IRenderSystem.h"
#include "iwindow.h"

namespace core_services {

    class engine {
    public:
        engine();
        ~engine();

        /* Initialization methods */
        void register_subsystem( isubsystem *newSubsystem );
        void load_scene( std::string sceneFileName );

        /* Run methods */
        void begin_game_loop();

        /* Getters (and setters, if need be) */
        SceneFileLoader & get_scene_file_loader();
        transform_scene & get_transform_scene();

        void set_window( iwindow *new_window );
    private:
        SceneFileLoader fileLoader;
        transform_scene transformScene;
        std::vector<isubsystem*> subsystems;
        irender_system *m_render_system;
        iphysics_system *physicsSystem;

        iwindow *m_main_window;

        std::chrono::system_clock::duration frameTime;

        void tick();
        void doUpdateAndRender();
        void doPhysics();
    };
}
