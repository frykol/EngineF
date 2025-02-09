#include "Scene.h"

namespace EngineF{
    Scene::Scene(const std::string& name, glm::mat4 camera): m_Name(name), m_Camera(camera){
        m_ErrorObject.push_back(std::make_shared<GameObject>(ResourceManager::getInstance().getTexture("brick"), glm::vec2(300.0f, 300.0f),
        glm::vec2(600.0f,600.0f), glm::vec3(1.0f, 0.0f,0.0f)));
    }


    void Scene::testScene(){
        float maxLen = 10;
        std::shared_ptr<GameObject> testGameObject = std::make_shared<GameObject>(ResourceManager::getInstance().getTexture("brick"), glm::vec2(700.0f, 650.0f),
                                        glm::vec2(300.0f, 50.0f), glm::vec3(1.0f,0.2f,0.1f));
            m_GameObjects.push_back(testGameObject);
        for(float i = 0; i<maxLen; i++){
            std::shared_ptr<GameObject> testGameObject = std::make_shared<GameObject>(ResourceManager::getInstance().getTexture("brick"), glm::vec2(0 + i * (1280.0f/maxLen), 0),
                                        glm::vec2(1280.0f/maxLen,100.0f), glm::vec3(0.4f,1.0f,0.4f));
            m_GameObjects.push_back(testGameObject);
        }
        m_IsConstructed = true;
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

    std::vector<std::shared_ptr<GameObject>>& Scene::getGameObjects(){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return m_ErrorObject;
        }
        return m_GameObjects;
    }

    std::shared_ptr<GameObject> Scene::getGameObject(int index){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return m_ErrorObject[0];
        }
        if(index >= m_GameObjects.size() || index <= m_GameObjects.size()){
            std::string message = "Index out of range in: " + m_Name;
            LOG_E(message, LogType::ERROR, true);
            return m_ErrorObject[0];
        }
        return m_GameObjects[index];
    }



}