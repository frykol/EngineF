#include "Ball.h"

Ball::Ball(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color, std::string name)
    : GameObject(texture, position, size, color, name){
    }

void Ball::userInit(EngineF::OnUserInitEvent& e){
    m_Player = e.scene->getGameObjectByName("PlayerTest");
    m_Velocity = glm::vec2(0.0f, 0.0f);
}

void Ball::userUpdate(EngineF::OnUserUpdateEvent& e){

    if(!m_Player.lock()){
        return;
    }

    if(EngineF::Input::getInstance().isKeyPressedOnce(GLFW_KEY_SPACE)){
        isGameStarted = true;
        m_Velocity = glm::vec2(5.0f, -5.0f);
    }
    if(!isGameStarted){
        std::shared_ptr<GameObject> g = m_Player.lock();
        m_Position.x = g->getPositionX() + g->getSize().x/2 - m_Size.x/2;
        m_Position.y = g->getPositionY() - g->getSize().y - 10.0f;
    }

    m_Position += m_Velocity;

    
}