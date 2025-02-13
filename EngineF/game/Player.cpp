#include "Player.h"

Player::Player(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color)
    : GameObject(texture, position, size, color){
        m_OnMouseMoveID = EngineF::EventManager::getInstance().addListener<EngineF::OnMouseMoveEvent>([this](EngineF::OnMouseMoveEvent& e){
            this->onMouseMove(e);
        });
        
    }

Player::~Player(){
    EngineF::EventManager::getInstance().removeListener<EngineF::OnMouseMoveEvent>(m_OnMouseMoveID);
}


void Player::userInit(EngineF::OnUserInitEvent& e){
    addComponent<EngineF::CollisionComponent>();
}

void Player::userUpdate(EngineF::OnUserUpdateEvent& e){
    // m_Position.x += 10.0f * m_Dir;
    // if(m_Position.x <= 0.0f || m_Position.x + m_Size.x >= 1280.0f){
    //     m_Dir *= -1;
    // }
}

void Player::onMouseMove(EngineF::OnMouseMoveEvent& e){
    float mouseX = static_cast<float>(e.mouseX);
    float mouseY = static_cast<float>(e.mouseY);

    m_Position.x =  mouseX - m_Size.x / 2;
    m_Position.y =  mouseY - m_Size.y / 2;
}

void Player::onCollision(EngineF::GameObject* collision){
    EngineF::LOG("COLLISION", EngineF::LogType::MESSAGE);
    collision->setIsAlive(false);
}