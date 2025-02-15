#include "CollisionComponent.h"

namespace EngineF{
    std::vector<CollisionComponent*> CollisionComponent::m_Collisions;

    CollisionComponent::CollisionComponent(GameObject* gameObject, CollisionComponent::CollisionType collisionType,const glm::vec2& boundary)
    : Component(gameObject), m_CollisionType(collisionType),m_Boundary(boundary){
        m_Collisions.push_back(this);
    }

    CollisionComponent::CollisionComponent(GameObject* gameObject,CollisionComponent::CollisionType collisionType, float radius)
    :Component(gameObject), m_CollisionType(collisionType),m_Boundary(glm::vec2(radius, radius)){
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
            if(m_CollisionType == CollisionComponent::CollisionType::Box && collision->getCollisionType() == CollisionComponent::CollisionType::Box){
                if(m_Owner->getPositionX() < collision->getOwner()->getPositionX() + collision->getBoundary().x
                && m_Owner->getPositionX() + m_Boundary.x > collision->getOwner()->getPositionX()
                && m_Owner->getPositionY() < collision->getOwner()->getPositionY() + collision->getBoundary().y 
                && m_Owner->getPositionY() + getBoundary().y > collision->getOwner()->getPositionY()
                ){
                    m_Owner->onCollision(collision);
                }
            }
            if(m_CollisionType == CollisionComponent::CollisionType::Circle && collision->getCollisionType() == CollisionComponent::CollisionType::Box
            || m_CollisionType == CollisionComponent::CollisionType::Box && collision->getCollisionType() == CollisionComponent::CollisionType::Circle){
                CollisionComponent* circle;
                CollisionComponent* box;

                if(m_CollisionType == CollisionComponent::CollisionType::Circle){
                    circle = this;
                    box = collision;
                }else{
                    circle = collision;
                    box = this;
                }


                glm::vec2 center(circle->getOwner()->getPosition() + circle->getBoundary());
                glm::vec2 collisionHalfExtensts(box->getBoundary().x / 2.0f, box->getBoundary().y / 2.0f);
                glm::vec2 collisionCenter(box->getOwner()->getPositionX() + collisionHalfExtensts.x,
                                          box->getOwner()->getPositionY() + collisionHalfExtensts.y);
                glm::vec2 difference = center - collisionCenter;
                glm::vec2 clamped = glm::clamp(difference, -collisionHalfExtensts, collisionHalfExtensts);
                glm::vec2 closest = collisionCenter + clamped;

                difference = closest - center;
                if(glm::length(difference) < circle->getBoundary().x){
                    m_Difference = difference;
                    m_Owner->onCollision(collision);
                }
            }
        }
    }

    glm::vec2& CollisionComponent::getBoundary(){
        return m_Boundary;
    }

    glm::vec2& CollisionComponent::getDiffrence(){
        return m_Difference;
    }

    GameObject* CollisionComponent::getOwner(){
        return m_Owner;
    }
    CollisionComponent::CollisionType CollisionComponent::getCollisionType(){
        return m_CollisionType;
    }
    
}