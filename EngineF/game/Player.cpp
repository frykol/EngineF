#include "Player.h"

Player::Player(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color)
    : GameObject(texture, position, size, color){
        m_OnMouseMoveID = EngineF::EventManager::getInstance().addListener<EngineF::OnMouseMoveEvent>([this](EngineF::OnMouseMoveEvent& e){
            this->onMouseMove(e);
        });
    }

void Player::userUpdate(EngineF::OnUserUpdateEvent& e){
    // m_Position.x += 10.0f * m_Dir;
    // if(m_Position.x <= 0.0f || m_Position.x + m_Size.x >= 1280.0f){
    //     m_Dir *= -1;
    // }
}

void Player::onMouseMove(EngineF::OnMouseMoveEvent& e){
    m_Position.x =  static_cast<float>(e.mouseX) - m_Size.x / 2;
    m_Position.y =  static_cast<float>(e.mouseY) - m_Size.y / 2;
}