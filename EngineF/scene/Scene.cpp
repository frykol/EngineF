#include "Scene.h"

namespace EngineF{
    Scene::Scene(const std::string& name, glm::mat4 camera): m_Name(name), m_Camera(camera){
        m_GameObjectCreatedID = EventManager::getInstance().addListener<GameObjectCreatedEvent>([this](GameObjectCreatedEvent& e){
            this->addGameObjectTest(e);
        });

    }


    void Scene::testScene(){
        float maxLen = 10;
            
        for(float i = 0; i<maxLen; i++){
            new GameObject(ResourceManager::getInstance().getTexture("brick"), glm::vec2(0 + i * (1280.0f/maxLen), 0),
            glm::vec2(1280.0f/maxLen,100.0f), glm::vec3(0.4f,1.0f,0.4f));
        }
        m_IsConstructed = true;
    }

    GameObject* Scene::addGameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color){
        std::unique_ptr<GameObject> gameObject = std::make_unique<GameObject>(texture, position, size, color);
        GameObject* gameObjectToReturn = gameObject.get();
        m_GameObjects.push_back(std::move(gameObject));
        return gameObjectToReturn;
    }

    void Scene::addGameObjectTest(GameObjectCreatedEvent& e){
        GameObject* g = e.gameObject;
        //std::unique_ptr<GameObject> gameObject(std::move(g));
        m_GameObjects.push_back(std::move(std::unique_ptr<GameObject>(g)));
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

    std::vector<std::unique_ptr<GameObject>>& Scene::getGameObjects(){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
        }
        return m_GameObjects;
    }

    GameObject* Scene::getGameObject(int index){
        if(!m_IsConstructed){
            std::string message = "Scene: " + m_Name + " is not constructed";
            LOG_E(message, LogType::ERROR, true);
            return nullptr;
        }
        if(index >= m_GameObjects.size() || index < 0){
            std::string message = "Index out of range in: " + m_Name;
            LOG_E(message, LogType::ERROR, true);
            return nullptr;
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