#include "FontRenderer.h"

namespace EngineF{
    FontRenderer::FontRenderer(Shader& shader): m_Shader(shader){
        initBuffer();
    }

    void FontRenderer::initBuffer(){
        glGenVertexArrays(1, &m_FontVAO);
        glGenBuffers(1, &m_FontVBO);
        glBindVertexArray(m_FontVAO);
        glBindBuffer(GL_ARRAY_BUFFER, m_FontVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0); 
    }

    void FontRenderer::drawText(Font& font, const std::string& text, const glm::vec2& position,float scale, const glm::vec3& color){
        m_Shader.bind();
        m_Shader.setUniform3f("u_Color", color.x, color.y, color.z);


        float posX = position.x;
        float posY = position.y;

        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(m_FontVAO);
        std::string::const_iterator c;
        for(c = text.begin(); c != text.end(); c++){
            Character& ch = font.getCharacter(*c);

            float xpos = posX + ch.bearing.x * scale;
            float ypos = posY - (ch.size.y - ch.bearing.y) * scale;

            float w = ch.size.x * scale;
            float h = ch.size.y * scale;
            // update VBO for each character
            float vertices[6][4] = {
                { xpos,     ypos + h,   0.0f, 0.0f },            
                { xpos,     ypos,       0.0f, 1.0f },
                { xpos + w, ypos,       1.0f, 1.0f },

                { xpos,     ypos + h,   0.0f, 0.0f },
                { xpos + w, ypos,       1.0f, 1.0f },
                { xpos + w, ypos + h,   1.0f, 0.0f }           
            };

            ch.texture.bind();
            glBindBuffer(GL_ARRAY_BUFFER, m_FontVBO);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glDrawArrays(GL_TRIANGLES, 0, 6);
            ch.texture.unBind();
            posX += (ch.advance >> 6) * scale;
        }
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}