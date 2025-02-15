#include "CollisionComponent.h"

namespace EngineF{
    std::vector<CollisionComponent*> CollisionComponent::m_Collisions;

    CollisionComponent::CollisionComponent(GameObject* gameObject, CollisionComponent::CollisionType collisionType,const glm::vec2& boundary): Component(gameObject), m_CollisionType(collisionType),m_Boundary(boundary){
        m_Collisions.push_back(this);
    }

    CollisionComponent::~CollisionComponent(){
        
        for(int i = 0; i<m_Collisions.size(); i++){
            if(this == m_Collisions[i]){
                LOG("Collision Destroyed", LogType::WARNING);
                m_Collisions.erase(m_Collisions.begin() + i);
            }
        }
    }

    void CollisionComponent::init(){

    }

    void CollisionComponent::update(){
        if(m_Collisions.size() < 2)
            return;

        for(CollisionComponent* collision : m_Collisions){

            if(this == collision)
                continue;

            if(m_Owner->getPositionX() < collision->getOwner()->getPositionX() + collision->getOwner()->getSize().x
            && m_Owner->getPositionX() + m_Owner->getSize().x > collision->getOwner()->getPositionX()
            && m_Owner->getPositionY() < collision->getOwner()->getPositionY() + collision->getOwner()->getSize().y 
            && m_Owner->getPositionY() + m_Owner->getSize().y > collision->getOwner()->getPositionY()
            ){
                m_Owner->onCollision(collision);
            }
        }
    }

    glm::vec2& CollisionComponent::getBoundary(){
        return m_Boundary;
    }

    GameObject* CollisionComponent::getOwner(){
        return m_Owner;
    }
    
}