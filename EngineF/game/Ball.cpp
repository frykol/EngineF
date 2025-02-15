#include "Ball.h"

Ball::Ball(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color, std::string name)
    : GameObject(texture, position, size, color, name){
}

void Ball::userInit(EngineF::OnUserInitEvent& e){
    m_Player = e.scene->getGameObjectByName("PlayerTest");
    m_Velocity = glm::vec2(0.0f, 0.0f);
    m_InitialVelocity = glm::vec2(10.0f, -10.0f);

    addComponent<EngineF::CollisionComponent>(EngineF::CollisionComponent::CollisionType::Circle, m_Size.x/2);
}

void Ball::userUpdate(EngineF::OnUserUpdateEvent& e){

    if(!m_Player.lock()){
        return;
    }

    if(EngineF::Input::getInstance().isKeyPressedOnce(GLFW_KEY_SPACE)){
        isGameStarted = true;
        m_Velocity = m_InitialVelocity;
    }
    if(!isGameStarted){
        std::shared_ptr<GameObject> g = m_Player.lock();
        m_Position.x = g->getPositionX() + g->getSize().x/2 - m_Size.x/2;
        m_Position.y = g->getPositionY() - g->getSize().y - 10.0f;
    }

    if(m_Position.y + m_Size.y >= 720.0f || m_Position.y <= 0.0f){
        m_Velocity.y *= -1;
    }

    if(m_Position.x + m_Size.x >= 1280.0f || m_Position.x <= 0.0f){
        m_Velocity.x *= -1;
    }

    m_Position += m_Velocity;

    
}

void Ball::onCollision(EngineF::CollisionComponent* collision){

    glm::vec2 compass[] = {
        glm::vec2( 0.0f,  1.0f),
        glm::vec2( 1.0f,  0.0f),	
        glm::vec2( 0.0f, -1.0f),	
        glm::vec2(-1.0f,  0.0f)	
    };
    glm::vec2& difference = collision->getDiffrence();
    float max = 0.0f;
    unsigned int bestMatch = -1;
    for (unsigned int i = 0; i < 4; i++)
    {
        float dotProduct = glm::dot(glm::normalize(difference), compass[i]);
        if (dotProduct > max)
        {
            max = dotProduct;
            bestMatch = i;
        }
    }

    if(collision->getOwner()->getName() != "PlayerTest"){
        if(bestMatch == 1 || bestMatch == 3){
            m_Velocity.x *= -1;
            float penetration = m_Size.x/2 - std::abs(difference.x);
            if(bestMatch == 3){
                m_Position.x += penetration;
            }else{
                m_Position.x -= penetration;
            }
        }
        if(bestMatch == 0 || bestMatch == 2){
            m_Velocity.y *= -1;
            float penetration = m_Size.y/2 - std::abs(difference.y);
            if(bestMatch == 0){
                m_Position.y -= penetration;
            }else{
                m_Position.y += penetration;
            }
        }
        collision->getOwner()->setIsAlive(false);
    }   
    else{
        std::shared_ptr<GameObject> player = m_Player.lock();
        float centerBoard = player->getPositionX() + player->getSize().x / 2.0f;
        float distance = (m_Position.x + m_Size.x/2) - centerBoard;
        float percentage = distance / (player->getSize().x / 2.0f);
        float strength = 2.0f;
        glm::vec2 oldVelocity = m_Velocity;
        m_Velocity.x = m_InitialVelocity.x * percentage * strength;
        m_Velocity.y = -1.0f * abs(m_Velocity.y);
        m_Velocity = glm::normalize(m_Velocity) * glm::length(oldVelocity);
    }
}