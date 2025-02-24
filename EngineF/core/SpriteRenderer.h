#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../Logger.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace EngineF{
    class SpriteRenderer{
        private:

            Shader m_Shader;

            unsigned int m_QuadVAO;
            void initQuadVAO();

        public:
            static void clear(glm::vec3 color = glm::vec3(0.0f,0.0f,0.0f));
            void drawSprite(Texture& texture ,const glm::vec2& position,const glm::vec2& size,const glm::vec3& color);

            void drawSpriteNoTexture(glm::vec2 position, glm::vec2 size, glm::vec3 color);

            SpriteRenderer(Shader& shader);


            
    };
}