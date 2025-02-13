#pragma once

#include "../scene/GameObject.h"

#include "../components/CollisionComponent.h"

class Player : public EngineF::GameObject{
    private:
        int m_Dir = 1;

        EngineF::ListenerID m_OnMouseMoveID;
    public:
        Player(std::shared_ptr<EngineF::Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color);
        ~Player();

        void userInit(EngineF::OnUserInitEvent& e) override;
        void userUpdate(EngineF::OnUserUpdateEvent& e) override;

        void onMouseMove(EngineF::OnMouseMoveEvent& e);

        void onCollision(EngineF::GameObject* collision) override;
};