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
            static std::vector<CollisionComponent*> m_Collisions;

            CollisionComponent::CollisionType m_CollisionType;

            glm::vec2 m_Boundary;
        public:
            CollisionComponent(GameObject* gameObject, CollisionComponent::CollisionType collisionType = CollisionComponent::CollisionType::Box,const glm::vec2& boundary = glm::vec2(50.0f, 50.0f));
            ~CollisionComponent();

            void update() override;
            void init() override;

            glm::vec2& getBoundary();
            GameObject* getOwner();
    };
}