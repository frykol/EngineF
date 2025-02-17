#include "Player.h"

Player::Player(glm::vec2 position, glm::vec2 size, std::string name)
    : GameObject(position, size, name){
        
    }

Player::~Player(){
}


void Player::userInit(EngineF::OnUserInitEvent& e){
}

void Player::userUpdate(EngineF::OnUserUpdateEvent& e){
    if(m_Position.x <= 0.0f){
        m_Position.x = 0.0f;
    }

    if(m_Position.x + m_Size.x >= 1280.0f){
        m_Position.x = 1280.0f - m_Size.x;
    }
    if(EngineF::Input::getInstance().isKeyPressed(GLFW_KEY_D)){
        m_Position.x += 10.0f;
    }
    else if(EngineF::Input::getInstance().isKeyPressed(GLFW_KEY_A)){
        m_Position.x -= 10.0f;
    }
}


void Player::onCollision(EngineF::CollisionComponent* collision){
}