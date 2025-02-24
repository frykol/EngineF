#include "ResourceManager.h"

namespace EngineF{
    std::map<std::string, std::shared_ptr<Shader>> ResourceManager::m_Shaders;
    std::map<std::string, std::shared_ptr<Texture>> ResourceManager::m_Textures;
    std::map<std::string, std::shared_ptr<Font>> ResourceManager::m_Fonts;

    std::shared_ptr<Shader> ResourceManager::loadShader(const char* vertexPath, const char* fragmentPath, const std::string& name){
        m_Shaders[name] = std::make_shared<Shader>(vertexPath, fragmentPath, name.c_str());
        return m_Shaders[name];
    }   
    std::shared_ptr<Shader> ResourceManager::getShader(const std::string& name){
        return m_Shaders[name];
    }

    std::shared_ptr<Texture> ResourceManager::loadTexture(const char* texturePath, const std::string& name){
        m_Textures[name] = std::make_shared<Texture>();
        m_Textures[name]->createTexture(texturePath);
        return m_Textures[name];
    }

    std::shared_ptr<Texture> ResourceManager::getTexture(const std::string& name){
        return m_Textures[name];
    }

    std::shared_ptr<Font> ResourceManager::loadFont(const std::string& fontPath, const std::string& name){
        m_Fonts[name] = std::make_shared<Font>(fontPath);
        m_Fonts[name]->createFont();
        return m_Fonts[name];
    }
    std::shared_ptr<Font> ResourceManager::getFont(const std::string& name){
        return m_Fonts[name];
    }
}