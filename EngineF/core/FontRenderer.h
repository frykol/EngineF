#pragma once


#include "Shader.h"
#include "Font.h"

namespace EngineF{
    class FontRenderer{
        private:
            unsigned int m_FontVAO;
            unsigned int m_FontVBO;

            Shader m_Shader;
        
        public:
            FontRenderer(Shader& shader);

            void initBuffer();
            void drawText(Font& font, const std::string& text, const glm::vec2& position,float scale, const glm::vec3& color);
            void test();
    };
}