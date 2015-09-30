#pragma once

#include "stdafx.h"

namespace CoreServices {
    class Time {
    public:
        static std::chrono::system_clock::time_point curTime;
        static std::chrono::duration<int, std::milli> deltaTime;
        static std::chrono::duration<int, std::milli> fixedTimeStep;
    };
}
