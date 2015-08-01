#pragma once

namespace CoreServices {
    /*~\brief Defines an interface for anyone wishing to implement their own scene*/
    template <class T>
    class IScene {
    public:
        virtual std::vector<T> getComponents() = 0;
    };
}
