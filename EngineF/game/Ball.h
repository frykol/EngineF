#pragma once
#include "../core/Application.h"
#include "../scene/GameObject.h"

#include "../core/Input.h"

class Ball : public EngineF::GameObject{
    private:
        EngineF::Input* m_Input;

        std::weak_ptr<GameObject> m_Player;
        glm::vec2 m_Velocity;
        glm::vec2 m_InitialVelocity;
        bool isGameStarted = false;
        
    public:
        Ball(glm::vec2 position, glm::vec2 size, std::string name = "BallTest");
        void userInit(EngineF::OnUserInitEvent& e) override;
        void userUpdate(EngineF::OnUserUpdateEvent& e) override;

        void onCollision(EngineF::CollisionComponent* collision) override;
};