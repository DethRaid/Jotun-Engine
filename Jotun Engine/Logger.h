#pragma once

#include <exception>

namespace core_services {
    /*!\brief Class that can log to console, filesystem, whatever
    
    This class itself doesn't output to logs. It just passes log messages to the LogOutput, which is fully static and thread safe*/
    class Logger {
    public:
        ~Logger();

    private:
        Logger();
    };
}
