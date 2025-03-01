#include "TextComponent.h"

namespace EngineF{
    TextComponent::TextComponent(GameObject* gameObject, std::shared_ptr<Font> font, std::string text, const glm::vec2& position, float scale, const glm::vec3& color)
    : Component(gameObject),m_Font(font), m_Text(text), m_Position(position), m_Scale(scale), m_Color(color){
        m_OnTextDrawID = EventManager::getInstance().addListener<OnTextDrawEvent>([this](OnTextDrawEvent& e){
            this->onTextDraw(e);
        });
    }
    TextComponent::~TextComponent(){
        EventManager::getInstance().removeListener<OnTextDrawEvent>(m_OnTextDrawID);
    }

    void TextComponent::onTextDraw(OnTextDrawEvent& e){
        e.fontRenderer->drawText(*m_Font, m_Text, m_Position, m_Scale, m_Color);
    }

    void TextComponent::setText(const std::string& text){
        m_Text = text;
    }

    std::string TextComponent::getText(){
        return m_Text;
    }
}