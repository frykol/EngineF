#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../Logger.h"
#include "Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace EngineF{
    class SpriteRenderer{
        private:

            Shader m_Shader;

            unsigned int m_QuadVAO;
            void initQuadVAO();

        public:
            void drawSprite(glm::vec2 position, glm::vec2 size, glm::vec3 color);

            SpriteRenderer(Shader& shader);
            ~SpriteRenderer();
    };
}