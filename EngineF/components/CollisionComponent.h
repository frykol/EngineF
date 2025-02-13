#pragma once

#include <vector>

#include "../Logger.h"
#include "Component.h"


namespace EngineF{
    class CollisionComponent : public Component{
        private:
            static std::vector<GameObject*> m_CollisionGameObjects;
        public:
            CollisionComponent(GameObject* gameObject);
            ~CollisionComponent();

            void update() override;
            void init() override;
    };
}