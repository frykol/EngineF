#pragma once

#include <string>

namespace EngineF{
    class Event{
        public:
            virtual const std::string GetEventType() const = 0;

            bool Handled = false;
    };
}