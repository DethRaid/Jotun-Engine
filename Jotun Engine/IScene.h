#pragma once

#include "stdafx.h"

namespace CoreServices {
    /*!\brief Defines an interface for anyone wishing to implement their own scene*/
    // TODO: More useful getting functions
    template <class T>
    class Scene {
    public:
        Scene() {}
        virtual ~Scene() {}

        const std::vector<T> & getComponents() const;

    protected:
        std::vector<T> components;
    };

    template<class T>
    inline const std::vector<T>& Scene<T>::getComponents() const {
        return components;
    }
}
