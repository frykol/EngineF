#include "SpriteRenderer.h"

namespace EngineF
{
    SpriteRenderer::SpriteRenderer(Shader& shader): m_Shader(shader){
        initQuadVAO();
    }


    void SpriteRenderer::initQuadVAO(){
        float data[]={
            0.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f
        };
        unsigned int VBO;
        GLLOG([this]{glGenVertexArrays(1, &this->m_QuadVAO);});
        

        GLLOG([&VBO]{glGenBuffers(1, &VBO);});
        GLLOG([&VBO]{glBindBuffer(GL_ARRAY_BUFFER, VBO);});
        
        GLLOG([data]{glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);});


        GLLOG([this]{glBindVertexArray(this->m_QuadVAO);});
        GLLOG([]{glEnableVertexAttribArray(0);});
        GLLOG([]{glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);});

        GLLOG([]{glBindBuffer(GL_ARRAY_BUFFER, 0);});
        GLLOG([]{glBindVertexArray(0);});
    }

    void SpriteRenderer::drawSprite(){
        m_Shader.bind();
        GLLOG([this]{glBindVertexArray(this->m_QuadVAO);});
        GLLOG([]{glDrawArrays(GL_TRIANGLES, 0, 6);});
        GLLOG([]{glBindVertexArray(0);});
    }
}
