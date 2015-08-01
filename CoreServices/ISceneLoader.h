#pragma once

namespace CoreServices {
    /*!\brief Defines an interface for all scene loaders*/
    class ISceneLoader {
    public:
        virtual void loadSceneFromJson( rapidjson::Value &json ) = 0;
    };
}
