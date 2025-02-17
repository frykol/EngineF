#include "Scene.h"

#include "glm/gtc/matrix_transform.hpp"

#include "GameObject.h"

#include "../core/ResourceManager.h"

#include "../components/CollisionComponent.h"

namespace EngineF{
    Scene::Scene(const std::string& name, glm::mat4 camera): m_Name(name), m_Camera(camera){
        m_GameObjectCreatedID = EventManager::getInstance().addListener<GameObjectCreatedEvent>([this](GameObjectCreatedEvent& e){
            this->addGameObjectTest(e);
        });

    }


    void Scene::testScene(){
        float maxLen = 10;
            
        for(float i = 0; i<maxLen; i++){
            new GameObject(glm::vec2(0 + i * (1280.0f/maxLen), 0),
            glm::vec2(1280.0f/maxLen,100.0f));
        }
        m_IsConstructed = true;
    }

    void Scene::addGameObjectTest(GameObjectCreatedEvent& e){
        GameObject* g = e.gameObject;
        //std::unique_ptr<GameObject> gameObject(std::move(g));
        m_GameObjects.push_back(std::move(std::shared_ptr<GameObject>(g)));
        LOG("Added", LogType::MESSAGE);
    }

    void Scene::removeGameObject(int index){
        if(m_GameObjects.empty())
            return;
        m_GameObjects.erase(m_GameObjects.begin() + index);
    }

    void Scene::setName(std::string name){
        m_Name = name;
    }
    std::string Scene::getName(){
        return m_Name;
    }

    void Scene::setCamera(glm::mat4 camera){
        m_Camera = camera;
    }

    glm::mat4 Scene::getCamera(){
        return m_Camera;
    }


    std::weak_ptr<GameObject> Scene::getGameObject(int index){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return std::weak_ptr<GameObject>();
        }
        if(index >= m_GameObjects.size() || index < 0){
            std::string message = "Index out of range in: " + m_Name;
            LOG_E(message, LogType::ERROR, true);
            return std::weak_ptr<GameObject>();
        }
        return std::weak_ptr(m_GameObjects[index]);
    }

    std::weak_ptr<GameObject> Scene::getGameObjectByName(const std::string& name){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return std::weak_ptr<GameObject>();
        }

        for(int i = 0; i<m_GameObjects.size(); i++){
            if(m_GameObjects[i]->getName() == name){
                return std::weak_ptr(m_GameObjects[i]);
            }
        }
        std::string msg = "GameObject " + name + " not found"; 
        LOG(msg, LogType::WARNING);
        return std::weak_ptr<GameObject>();
    }

    void Scene::destroyNotAliveGameObjects(){
        for(int i = 0; i<m_GameObjects.size(); i++){
            if(!m_GameObjects[i]->getIsAlive()){
                m_GameObjects.erase(m_GameObjects.begin() + i);
            }
        }
    }

    size_t Scene::getGameObjectsCount(){
        return m_GameObjects.size();
    }

}