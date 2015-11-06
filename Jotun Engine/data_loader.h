#pragma once

#include "stdafx.h"

namespace core_services {
    /*!\brief Class for loading non-component data.
    
    Non-component data includes things like textures, materials, shaders, animations, meshes, audio files, data files,
    etc. Anything that's stored in a scene file but isn't a component*/
    class data_loader {
    public:
        virtual void load_data( rapidjson::Value &json ) = 0;
    };
}
