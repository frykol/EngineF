#include "Player.h"

Player::Player(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color, std::string name)
    : GameObject(texture, position, size, color, name){
        
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
    EngineF::LOG("COLLISION", EngineF::LogType::MESSAGE);
    //collision->setIsAlive(false);
}