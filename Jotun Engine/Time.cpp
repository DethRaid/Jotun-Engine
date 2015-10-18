#include "stdafx.h"
#include "Time.h"

namespace core_services {
    std::chrono::system_clock::time_point Time::curTime;
    std::chrono::duration<int, std::milli> Time::deltaTime;
    std::chrono::duration<int, std::milli> Time::fixedTimeStep;
}