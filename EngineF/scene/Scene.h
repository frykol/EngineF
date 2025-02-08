#pragma once

#include <string>
#include <memory>
#include <vector>
#include "GameObject.h"
#include "../core/ResourceManager.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../Logger.h"

namespace EngineF{
    class Scene{
        private:
            std::string m_Name;

            glm::mat4 m_Camera;
            std::vector<std::shared_ptr<GameObject>> m_GameObjects;

            bool m_IsConstructed;

            std::vector<std::shared_ptr<GameObject>> m_ErrorObject;
        public:

            Scene(const std::string& m_Name, glm::mat4 camera = glm::mat4(1.0f));


            void constructScene(); 
            void testScene();

            void setName(std::string name);
            std::string getName();

            void setCamera(glm::mat4 camera);
            glm::mat4 getCamera();


            std::vector<std::shared_ptr<GameObject>>& getGameObjects();

            std::shared_ptr<GameObject> getGameObject(int index);
    };
}