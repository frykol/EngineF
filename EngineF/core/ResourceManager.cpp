#include "ResourceManager.h"

namespace EngineF{
    std::map<std::string, std::shared_ptr<Shader>> ResourceManager::m_Shaders;
    std::map<std::string, std::shared_ptr<Texture>> ResourceManager::m_Textures;

    std::shared_ptr<Shader> ResourceManager::loadShader(const char* vertexPath, const char* fragmentPath, std::string name){
        m_Shaders[name] = std::make_shared<Shader>(vertexPath, fragmentPath, name.c_str());
        return m_Shaders[name];
    }   
    std::shared_ptr<Shader> ResourceManager::getShader(std::string name){
        return m_Shaders[name];
    }

    std::shared_ptr<Texture> ResourceManager::loadTexture(const char* texturePath, std::string name){
        m_Textures[name] = std::make_shared<Texture>(texturePath);
        return m_Textures[name];
    }

    std::shared_ptr<Texture> ResourceManager::getTexture(std::string name){
        return m_Textures[name];
    }
}