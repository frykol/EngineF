#pragma once

#include <string>
#include <memory>
#include <vector>
#include "GameObject.h"
#include "../core/ResourceManager.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../Logger.h"

#include "../events/EventManager.h"
#include "../events/GameObjectCreatedEvent.h"

#include "../components/CollisionComponent.h"

namespace EngineF{
    class Scene{
        private:
            std::string m_Name;

            glm::mat4 m_Camera;

            
            std::vector<std::unique_ptr<GameObject>> m_GameObjects;

            bool m_IsConstructed;


            ListenerID m_GameObjectCreatedID;
        public:

            Scene(const std::string& m_Name, glm::mat4 camera = glm::mat4(1.0f));


            void constructScene(); 
            void testScene();

            void setName(std::string name);
            std::string getName();

            void setCamera(glm::mat4 camera);
            glm::mat4 getCamera();

            GameObject* addGameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color);

            void addGameObjectTest(GameObjectCreatedEvent& e);

            void removeGameObject(int index);

            std::vector<std::unique_ptr<GameObject>>& getGameObjects();

            GameObject* getGameObject(int index);


            void destroyNotAliveGameObjects();
    };
}