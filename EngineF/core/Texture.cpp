#include "Texture.h"

namespace EngineF{
    
    Texture::Texture(){
    }

    void Texture::createTexture(const char* texturePath){
        stbi_set_flip_vertically_on_load(1);

        glGenTextures(1, &m_ID);
        glBindTexture(GL_TEXTURE_2D, m_ID);        

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        unsigned char* data = stbi_load(texturePath, &m_Width, &m_Height, &m_NrChanels, 0);

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
            textureMessage.append(texturePath);
            LOG(textureMessage, LogType::ERROR);
        }
        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Texture::createFontTexture(const FT_Face& face){
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glGenTextures(1, &m_ID);
        glBindTexture(GL_TEXTURE_2D, m_ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        m_Status = 1;
    }

    void Texture::bind() const{
        if(m_Status != 1){
            std::string message("Cant bind the texture with id: ");
            message.append(std::to_string(m_ID));
            LOG(message, LogType::ERROR);
            return;
        }
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }

    void Texture::unBind() const{
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}