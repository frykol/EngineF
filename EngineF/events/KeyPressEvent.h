#pragma once

#include "Event.h"

namespace EngineF{
    class KeyPressEvent: public Event{
        public:
            int keyCode;
            int action;


            KeyPressEvent(int key, int act) : keyCode(key), action(act){};

            const std::string GetEventType() const override {return "KeyPressEvent";}
    };
}