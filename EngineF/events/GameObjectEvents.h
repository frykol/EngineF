#pragma once

#include "Event.h"

#include "../core/SpriteRenderer.h"

namespace EngineF{

    class OnUserUpdateEvent : public Event{
        public:
            OnUserUpdateEvent(){};
            
            const std::string GetEventType() const override {return "OnUserUpdateEvent";}
    };

    class OnMouseMoveEvent: public Event{
        public:
            double mouseX;
            double mouseY;


            OnMouseMoveEvent(double x, double y) : mouseX(x), mouseY(y){};

            const std::string GetEventType() const override {return "KeyPressEvent";}
    };

    class OnDrawEvent : public Event{
        public:
            SpriteRenderer* spriteRenderer;

            OnDrawEvent(SpriteRenderer* renderer): spriteRenderer(renderer){};

            const std::string GetEventType() const override {return "OnDrawEvent";}
    };

    class KeyPressEvent: public Event{
        public:
            int keyCode;
            int action;


            KeyPressEvent(int key, int act) : keyCode(key), action(act){};

            const std::string GetEventType() const override {return "KeyPressEvent";}
    };
}