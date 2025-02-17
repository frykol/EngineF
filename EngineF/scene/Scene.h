#pragma once

#include <string>
#include <memory>
#include <vector>


#include "glm/glm.hpp"


#include "../Logger.h"

#include "../events/EventManager.h"
#include "../events/GameObjectCreatedEvent.h"



namespace EngineF{
    class GameObject;

    class Scene{
        private:
            std::string m_Name;

            glm::mat4 m_Camera;

            
            std::vector<std::shared_ptr<GameObject>> m_GameObjects;

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

            void addGameObjectTest(GameObjectCreatedEvent& e);

            void removeGameObject(int index);

            std::weak_ptr<GameObject> getGameObject(int index);

            std::weak_ptr<GameObject> getGameObjectByName(const std::string& name);

            size_t getGameObjectsCount();

            void destroyNotAliveGameObjects();
    };
}