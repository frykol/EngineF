#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../Logger.h"
#include "Shader.h"

namespace EngineF{
    class SpriteRenderer{
        private:

            Shader m_Shader;

            unsigned int m_QuadVAO;
            void initQuadVAO();

        public:
            void drawSprite();

            SpriteRenderer(Shader& shader);
            ~SpriteRenderer();
    };
}