#pragma once

#include <memory>
#include <vector>

#include "../core/SpriteRenderer.h"
#include "../core/Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace EngineF{
    class GameObject{
        private:
            std::shared_ptr<Texture> m_Texture;
            glm::vec2 m_Position;
            glm::vec2 m_Size;
            glm::vec3 m_Color;

            GameObject* m_Parent;
            std::vector<GameObject*> m_Childrens;

            bool m_IsActive;
            bool m_IsAlive;
            bool m_IsVisible;

            
        public:
            GameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color);
            ~GameObject();

            void setTexture(std::shared_ptr<Texture> texture);
            std::shared_ptr<Texture> getTexture();

            void setPosition(glm::vec2 position);
            glm::vec2 getPosition();

            void Init();

            void Draw(SpriteRenderer& renderer);

            void Update();

            void setParent(GameObject* parent);

            void addChild(GameObject* child);

            void removeAllChildren();

            void setPositionX(float x);
            float getPositionX();

            void setPositionY(float y);
            float getPositionY();

            void setSize(glm::vec2 size);
            glm::vec2 getSize();

            void setColor(glm::vec3 color);
            glm::vec3 getColor();

            bool getIsAlive();
            void setIsAlive(bool isAlive);

            bool getIsVisible();
            void setIsVisible(bool isVisible);

            bool getIsActive();
            void setIsActive(bool isActive);
    };
}