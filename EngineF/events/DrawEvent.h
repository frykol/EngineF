#pragma once

#include "Event.h"

#include "../core/SpriteRenderer.h"
#include "../core/FontRenderer.h"

namespace EngineF{
    class OnDrawEvent : public Event{
        public:
            SpriteRenderer* spriteRenderer;

            OnDrawEvent(SpriteRenderer* renderer): spriteRenderer(renderer){};

            const std::string GetEventType() const override {return "OnDrawEvent";}
    };

    class OnTextDrawEvent : public Event{
        public:
            FontRenderer* fontRenderer;
            
            OnTextDrawEvent(FontRenderer* renderer) : fontRenderer(renderer){};

            const std::string GetEventType() const override {return "OnTextDrawEvent";}
    };
}