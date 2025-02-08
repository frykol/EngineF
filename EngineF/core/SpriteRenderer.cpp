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

    void SpriteRenderer::drawSpriteNoTexture(glm::vec2 position, glm::vec2 size, glm::vec3 color){
        m_Shader.bind();

        glm::mat4 model = glm::mat4(1.0f);
        model = translate(model, glm::vec3(position, 0.0f));

        model = glm::scale(model, glm::vec3(size, 1.0f));

        m_Shader.setUniformMat4("u_Model", model);
        m_Shader.setUniform3f("u_Color", color.x,color.y,color.z);

        GLLOG([this]{glBindVertexArray(this->m_QuadVAO);});
        GLLOG([]{glDrawArrays(GL_TRIANGLES, 0, 6);});
        GLLOG([]{glBindVertexArray(0);});
    }

    void SpriteRenderer::drawSprite(Texture& texture,glm::vec2 position, glm::vec2 size, glm::vec3 color){

        m_Shader.bind();

        glm::mat4 model = glm::mat4(1.0f);
        model = translate(model, glm::vec3(position, 0.0f));

        model = glm::scale(model, glm::vec3(size, 1.0f));

        m_Shader.setUniformMat4("u_Model", model);
        m_Shader.setUniform3f("u_Color", color.x,color.y,color.z);

        
        glActiveTexture(GL_TEXTURE0);
        texture.bind();

        GLLOG([this]{glBindVertexArray(this->m_QuadVAO);});
        GLLOG([]{glDrawArrays(GL_TRIANGLES, 0, 6);});
        GLLOG([]{glBindVertexArray(0);});
    }

    void SpriteRenderer::clear(glm::vec3 color){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(color.x, color.y, color.z, 1.0f);
    }

    void SpriteRenderer::swapBuffers(GLFWwindow* window){
        glfwSwapBuffers(window);
    }
}
