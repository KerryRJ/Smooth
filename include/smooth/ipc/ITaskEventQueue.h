//
// Created by permal on 6/27/17.
//

#pragma once

namespace smooth
{
    namespace ipc
    {
        class ITaskEventQueue
        {
            public:
                virtual void forward_to_task() = 0;
        };
    }
}