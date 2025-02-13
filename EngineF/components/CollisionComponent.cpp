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
        LOG("update Collision", LogType::MESSAGE);
    }

    void CollisionComponent::init(){
        
    }
}