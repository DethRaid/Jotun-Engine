#pragma once

#include "stdafx.h"

namespace core_services {
    /*!\brief Defines an interface for anyone wishing to implement their own scene*/
    // TODO: More useful getting functions
    template <class T>
    class scene {
    public:
        scene() {}
        virtual ~scene() {}

        const std::vector<T> & getComponents() const;

    protected:
        std::vector<T> m_components;
    };

    template<class T>
    inline const std::vector<T>& scene<T>::getComponents() const {
        return m_components;
    }
}
