#include "SpriteComponent.h"

#include "../scene/GameObject.h"
#include "../core/Texture.h"
#include "../core/SpriteRenderer.h"

namespace EngineF{
    SpriteComponent::SpriteComponent(GameObject* gameObject, std::shared_ptr<Texture> texture,const glm::vec3& color)
    : Component(gameObject), m_Texture(texture), m_Color(color){
        m_OnDrawID = EventManager::getInstance().addListener<OnDrawEvent>([this](OnDrawEvent& e) {
            this->onDraw(e);
        });
    }


    SpriteComponent::~SpriteComponent(){
        EventManager::getInstance().removeListener<OnDrawEvent>(m_OnDrawID);
    }

    void SpriteComponent::onDraw(OnDrawEvent& e){
        e.spriteRenderer->drawSprite(*m_Texture, m_Owner->getPosition(),m_Owner->getSize(), m_Color);
    }


    void SpriteComponent::setTexture(std::shared_ptr<Texture> texture){
        m_Texture = texture;
    }
    std::shared_ptr<Texture> SpriteComponent::getTexture(){
        return m_Texture;
    }

    void SpriteComponent::setColor(const glm::vec3& color){
        m_Color = color;
    }
    glm::vec3& SpriteComponent::getColor(){
        return m_Color;
    }
}