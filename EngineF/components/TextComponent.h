#pragma once

#include "Component.h"

#include "../core/Font.h"

#include "../events/EventManager.h"
#include "../events/DrawEvent.h"

namespace EngineF{
    class TextComponent : public Component{
        private:
            std::shared_ptr<Font> m_Font;
            std::string m_Text;
            glm::vec2 m_Position;
            float m_Scale;
            glm::vec3 m_Color;

            ListenerID m_OnTextDrawID;
        public:
            TextComponent(GameObject* gameObject, std::shared_ptr<Font> font, std::string text, const glm::vec2& position, float scale, const glm::vec3& color);
            ~TextComponent() override;

            void onTextDraw(OnTextDrawEvent& e);

            void setText(const std::string& text);
            std::string getText();
    };
}