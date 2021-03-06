// Smooth - C++ framework for writing applications based on Espressif's ESP-IDF.
// Copyright (C) 2017 Per Malmberg (https://github.com/PerMalmberg)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <condition_variable>
#include <mutex>
#include <deque>
#include <memory>
#include "ITaskEventQueue.h"

namespace smooth::core::ipc
{
    class QueueNotification
    {
        public:
            QueueNotification() = default;

            ~QueueNotification() = default;

            void notify(const std::weak_ptr<ITaskEventQueue>& queue);

            void remove_expired_queues();

            std::weak_ptr<ITaskEventQueue> wait_for_notification(std::chrono::milliseconds timeout);

            void clear()
            {
                std::lock_guard<std::mutex> lock(guard);
                queues.clear();
            }

        private:
            std::deque<std::weak_ptr<ITaskEventQueue>> queues{};
            std::mutex guard{};
            std::condition_variable cond{};
    };
}
