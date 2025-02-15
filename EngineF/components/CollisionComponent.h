#pragma once

#include <vector>

#include "../Logger.h"
#include "Component.h"


namespace EngineF{


    class CollisionComponent : public Component{
        public:
            enum CollisionType{
                Box = 0,
                Circle
            };
        private:
            static std::vector<GameObject*> m_CollisionGameObjects;

            CollisionComponent::CollisionType m_CollisionType;
        public:
            CollisionComponent(GameObject* gameObject, CollisionComponent::CollisionType collisionType = CollisionComponent::CollisionType::Box);
            ~CollisionComponent();

            void update() override;
            void init() override;

            
    };
}