#pragma once

#include "Component.h"

#include <memory>

#include "../events/EventManager.h"
#include "../events/DrawEvent.h"

#include "glm/glm.hpp"

namespace EngineF{
    class Texture;
    class SpriteComponent : public Component{
        private:
            std::shared_ptr<Texture> m_Texture;
            glm::vec3 m_Color;

            ListenerID m_OnDrawID;
        public:
            SpriteComponent(GameObject* gameObject, std::shared_ptr<Texture> texture,const glm::vec3& color = glm::vec3(1.0f, 0.0f, 0.0f));
            ~SpriteComponent();

            void init() override {};
            void update() override {};
            void onDraw(OnDrawEvent& e);

            void setTexture(std::shared_ptr<Texture> texture);
            std::shared_ptr<Texture> getTexture();

            void setColor(const glm::vec3& color);
            glm::vec3& getColor();
    };
}