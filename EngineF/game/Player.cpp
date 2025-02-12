#include "Player.h"

Player::Player(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color)
    : GameObject(texture, position, size, color){

    }

void Player::userUpdate(EngineF::OnUserUpdateEvent& e){
    // testPlayer->setPositionX(testPlayer->getPositionX() + 10.0f * dir);
    //     if(testPlayer->getPositionX() <= 0.0f || testPlayer->getPositionX() + testPlayer->getSize().x >= m_Width){
    //         dir *= -1;
    //     }
    m_Position.x += 10.0f * m_Dir;
    if(m_Position.x <= 0.0f || m_Position.x + m_Size.x >= 1280.0f){
        m_Dir *= -1;
    }
}