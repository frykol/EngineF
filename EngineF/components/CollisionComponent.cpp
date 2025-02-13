#include "CollisionComponent.h"

namespace EngineF{
    std::vector<GameObject*> CollisionComponent::m_CollisionGameObjects;

    CollisionComponent::CollisionComponent(GameObject* gameObject): Component(gameObject){
        m_CollisionGameObjects.push_back(gameObject);
    }

    CollisionComponent::~CollisionComponent(){

        
        for(int i = 0; i<m_CollisionGameObjects.size(); i++){
            if(m_Owner = m_CollisionGameObjects[i]){
                m_CollisionGameObjects.erase(m_CollisionGameObjects.begin() + i);
            }
        }
    }

    void CollisionComponent::update(){
        for(GameObject* gameObject : m_CollisionGameObjects){
            if(gameObject == m_Owner)
                continue;

            if(m_Owner->getPositionX() < gameObject->getPositionX() + gameObject->getSize().x
            && m_Owner->getPositionX() + m_Owner->getSize().x > gameObject->getPositionX()
            && m_Owner->getPositionY() < gameObject->getPositionY() + gameObject->getSize().y 
            && m_Owner->getPositionY() + m_Owner->getSize().y > gameObject->getPositionY()){
                LOG("EY YO", LogType::MESSAGE);
            }
        }
    }

    void CollisionComponent::init(){

    }
}