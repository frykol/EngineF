#pragma once

#include "Event.h"

#include "../core/SpriteRenderer.h"

namespace EngineF{
    class OnDrawEvent : public Event{
        public:
            SpriteRenderer* spriteRenderer;

            OnDrawEvent(SpriteRenderer* renderer): spriteRenderer(renderer){};

            const std::string GetEventType() const override {return "OnDrawEvent";}
    };
}