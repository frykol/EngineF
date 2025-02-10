#include "Scene.h"

namespace EngineF{
    Scene::Scene(const std::string& name, glm::mat4 camera): m_Name(name), m_Camera(camera){
        m_ErrorObject.push_back(std::make_unique<GameObject>(ResourceManager::getInstance().getTexture("brick"), glm::vec2(300.0f, 300.0f),
        glm::vec2(600.0f,600.0f), glm::vec3(1.0f, 0.0f,0.0f)));
    }


    void Scene::testScene(){
        float maxLen = 10;
        std::unique_ptr<GameObject> testGameObject = std::make_unique<GameObject>(ResourceManager::getInstance().getTexture("brick"), glm::vec2(700.0f, 650.0f),
                                        glm::vec2(300.0f, 50.0f), glm::vec3(1.0f,0.2f,0.1f));
            m_GameObjects.push_back(std::move(testGameObject));
        for(float i = 0; i<maxLen; i++){
            std::unique_ptr<GameObject> testGameObject = std::make_unique<GameObject>(ResourceManager::getInstance().getTexture("brick"), glm::vec2(0 + i * (1280.0f/maxLen), 0),
                                        glm::vec2(1280.0f/maxLen,100.0f), glm::vec3(0.4f,1.0f,0.4f));
            m_GameObjects.push_back(std::move(testGameObject));
        }
        m_IsConstructed = true;
    }

    GameObject* Scene::addGameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color){
        std::unique_ptr<GameObject> gameObject = std::make_unique<GameObject>(texture, position, size, color);
        GameObject* gameObjectToReturn = gameObject.get();
        m_GameObjects.push_back(std::move(gameObject));
        return gameObjectToReturn;
    }

    void Scene::removeGameObject(int index){
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

    std::vector<std::unique_ptr<GameObject>>& Scene::getGameObjects(){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return m_ErrorObject;
        }
        return m_GameObjects;
    }

    GameObject* Scene::getGameObject(int index){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return m_ErrorObject[0].get();
        }
        if(index >= m_GameObjects.size() || index < 0){
            std::string message = "Index out of range in: " + m_Name;
            LOG_E(message, LogType::ERROR, true);
            return m_ErrorObject[0].get();
        }
        return m_GameObjects[index].get();
    }

    void Scene::destroyNotAliveGameObjects(){
        for(int i = 0; i<m_GameObjects.size(); i++){
            if(!m_GameObjects[i]->getIsAlive()){
                m_GameObjects.erase(m_GameObjects.begin() + i);
            }
        }
    }

}