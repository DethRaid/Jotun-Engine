#pragma once
namespace core_services {
    class iwindow {
    public:
        virtual bool should_close() = 0;

        /*!\brief Performs window updating tasks, such as swapping buffers*/
        virtual void update_window() = 0;
    };
}
