#pragma once

#include "Event.h"



namespace EngineF{

    class OnUpdateEvent : public Event{
        public:
            OnUpdateEvent() {};

            const std::string GetEventType() const override {return "OnUpdateEvent";}
    };
    class Scene;

    class OnUserInitEvent : public Event{
        public:
            Scene* scene;

            OnUserInitEvent(Scene* scn): scene(scn){};

            const std::string GetEventType() const override {return "OnUserInitEvent";}
    };

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

    
}