#pragma once

#include "../scene/GameObject.h"

class Ball : public EngineF::GameObject{
    private:
        std::weak_ptr<GameObject> m_Player;
        glm::vec2 m_Velocity;
        bool isGameStarted = false;
    public:
        Ball(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color, std::string name = "BallTest");
        void userInit(EngineF::OnUserInitEvent& e) override;
        void userUpdate(EngineF::OnUserUpdateEvent& e) override;
};