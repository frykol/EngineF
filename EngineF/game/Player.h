#pragma once

#include "../scene/GameObject.h"


//#include "../components/CollisionComponent.h"

class Player : public EngineF::GameObject{
    private:
        int m_Dir = 1;

    public:
        Player(glm::vec2 position, glm::vec2 size, std::string name = "PlayerTest");
        ~Player();

        void userInit(EngineF::OnUserInitEvent& e) override;
        void userUpdate(EngineF::OnUserUpdateEvent& e) override;

        void onCollision(EngineF::CollisionComponent* collision) override;
};