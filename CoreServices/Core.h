#pragma once

#include "TransformScene.h"
#include "SceneFileLoader.h"
#include "ISubsystem.h"

namespace CoreServices {
    class Core : public ISubsystem {
    public:
        Core();
        ~Core();

        /* Core methods */
        SceneFileLoader & getSceneFileLoader();
        TransformScene & getTransformScene();

        /* ISubsystem methods */
        void init();
        void onLoadScene();
        void onUnloadScene();
        void onPreRender();
        void update();
        void fixedUpdate();
        void shutdown();
    private:
        SceneFileLoader fileLoader;
        TransformScene transformScene;
    };
}
