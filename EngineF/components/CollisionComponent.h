#pragma once

#include <vector>

#include "../Logger.h"
#include "Component.h"

#include "glm/glm.hpp"

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

            glm::vec2 m_Difference;
        public:
            CollisionComponent(GameObject* gameObject,CollisionComponent::CollisionType collisionType,const glm::vec2& boundary);
            CollisionComponent(GameObject* gameObject,CollisionComponent::CollisionType collisionType, float radius);
            ~CollisionComponent() override;

            void update() override;
            void init() override;

            glm::vec2& getBoundary();
            GameObject* getOwner();
            glm::vec2& getDiffrence();
            CollisionComponent::CollisionType getCollisionType();
    };
}