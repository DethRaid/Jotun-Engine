#pragma once

#include "ISubsystem.h"
#include "iwindow.h"

/*!\brief Interface for a system who wants to be the renderer*/
namespace core_services {
    class irender_system : public ISubsystem {
    public:
        virtual void render() = 0;
        virtual iwindow* get_window ()= 0;
    };
}

