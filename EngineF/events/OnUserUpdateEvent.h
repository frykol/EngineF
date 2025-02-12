#pragma once

#include "Event.h"

namespace EngineF{

    class OnUserUpdateEvent : public Event{
        public:
            OnUserUpdateEvent(){};
            
            const std::string GetEventType() const override {return "OnUserUpdateEvent";}
    };
}