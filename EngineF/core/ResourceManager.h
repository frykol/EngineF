#pragma once

#include <memory>
#include <map>
#include <string>

#include "Shader.h"
#include "Texture.h"
#include "Font.h"

namespace EngineF{

    class ResourceManager{
        private:
            static std::map<std::string, std::shared_ptr<Shader>> m_Shaders;
            static std::map<std::string, std::shared_ptr<Texture>> m_Textures;
            static std::map<std::string, std::shared_ptr<Font>> m_Fonts;

            ResourceManager() {};
            ResourceManager(ResourceManager const&);
            void operator=(ResourceManager const&);
        public:
            static ResourceManager& getInstance(){
                static ResourceManager instance;
                return instance;
            }

            //ResourceManager(ResourceManager const&) = delete;
            //void operator=(ResourceManager const&) = delete;

            

            std::shared_ptr<Shader> loadShader(const char* vertexPath, const char* fragmentPath, const std::string& name);
            std::shared_ptr<Shader> getShader(const std::string& name);
            std::shared_ptr<Texture> loadTexture(const char* texturePath, const std::string& name);
            std::shared_ptr<Texture> getTexture(const std::string& name);
            std::shared_ptr<Font> loadFont(const std::string& fontPath, const std::string& name);
            std::shared_ptr<Font> getFont(const std::string& name);
    };
}