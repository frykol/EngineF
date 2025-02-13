#pragma once

#include "Event.h"


namespace EngineF{

    class OnWindowResizeEvent : public Event{
        public:
            int width;
            int height;

            OnWindowResizeEvent(int w, int h): width(w), height(h) {};

            const std::string GetEventType() const override {return "OnWindowResize";}
    };
}