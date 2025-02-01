#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../Logger.h"


namespace EngineF{
    class SpriteRenderer{
        private:
            unsigned int m_QuadVAO;
            void initQuadVAO();

        public:
            void DrawSprite();

            SpriteRenderer();
            ~SpriteRenderer();
    };
}