#include "Texture.h"

namespace EngineF{
    
    Texture::Texture(const char* texturePath): m_TexturePath(texturePath){
        createTexture();
    }

    void Texture::createTexture(){
        stbi_set_flip_vertically_on_load(1);

        glGenTextures(1, &m_ID);
        glBindTexture(GL_TEXTURE_2D, m_ID);        

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        unsigned char* data = stbi_load(m_TexturePath, &m_Width, &m_Height, &m_NrChanels, 0);

        if(data){
            if(m_NrChanels == 3){
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            }
            if(m_NrChanels == 4){
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            }
            glGenerateMipmap(GL_TEXTURE_2D);
            m_Status = 1;
        }
        else{
            std::string textureMessage("Failed to load texture from path: ");
            textureMessage.append(m_TexturePath);
            LOG(textureMessage, LogType::ERROR);
        }
        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }


    void Texture::bind(){
        if(m_Status != 1){
            std::string message("Cant bind the texture with id: ");
            message.append(std::to_string(m_ID));
            LOG(message, LogType::ERROR);
            return;
        }
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }

    void Texture::unBind(){
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}