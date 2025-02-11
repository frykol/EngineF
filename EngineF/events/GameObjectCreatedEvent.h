#pragma once

#include "Event.h"

#include "../scene/GameObject.h"


namespace EngineF{

    class GameObject;

    class GameObjectCreatedEvent : public Event{
        public:
            GameObject* gameObject;


            GameObjectCreatedEvent(GameObject* gameObj): gameObject(gameObj){};

            const std::string GetEventType() const override {return "GameObjectCreatedEvent";}
    };
}