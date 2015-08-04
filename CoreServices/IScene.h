#pragma once

namespace CoreServices {
    /*!\brief Defines an interface for anyone wishing to implement their own scene*/
    // TODO: More useful getting functions
    template <class T>
    class IScene {
    public:
        virtual const std::vector<T> & getComponents() const = 0;
    };
}
