#include "stdafx.h"
#include "Time.h"

namespace CoreServices {
    std::chrono::system_clock::time_point Time::curTime;
    std::chrono::duration<int, std::milli> Time::deltaTime;
    std::chrono::duration<int, std::milli> Time::fixedTimeStep;
}