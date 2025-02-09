#pragma once

#include <memory>

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
        public:
            GameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color);

            void setTexture(std::shared_ptr<Texture> texture);
            std::shared_ptr<Texture> getTexture();

            void setPosition(glm::vec2 position);
            glm::vec2 getPosition();


            void setPositionX(float x);
            float getPositionX();

            void setPositionY(float y);
            float getPositionY();

            void setSize(glm::vec2 size);
            glm::vec2 getSize();

            void setColor(glm::vec3 color);
            glm::vec3 getColor();
    };
}