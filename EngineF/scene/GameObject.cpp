#include "GameObject.h"

namespace EngineF{
    GameObject::GameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color, std::string name)
    :m_Texture(texture), m_Position(position), m_Size(size), m_Color(color), m_IsVisible(true), m_IsAlive(true), m_IsActive(false), m_Name(name)
    {
        GameObject* gameObj = this;
        GameObjectCreatedEvent gameObjectCreatedEvent(gameObj);
        EventManager::getInstance().dispatchEvent(gameObjectCreatedEvent);

        m_OnDrawID = EventManager::getInstance().addListener<OnDrawEvent>([this](OnDrawEvent& e){
            this->draw(e);
        });

        m_OnUpdateID = EventManager::getInstance().addListener<OnUpdateEvent>([this](OnUpdateEvent& e){
            this->update(e);
        });

        m_OnUserInitID = EventManager::getInstance().addListener<OnUserInitEvent>([this](OnUserInitEvent& e){
            this->userInit(e);
        });

        m_OnUserUpdateID = EventManager::getInstance().addListener<OnUserUpdateEvent>([this](OnUserUpdateEvent& e){
            this->userUpdate(e);
        });
    }

    GameObject::~GameObject(){
        EventManager::getInstance().removeListener<OnDrawEvent>(m_OnDrawID);
        EventManager::getInstance().removeListener<OnUserUpdateEvent>(m_OnUserUpdateID);
        EventManager::getInstance().removeListener<OnUserUpdateEvent>(m_OnUpdateID);
        removeAllChildren();
        m_Components.clear();
        
        LOG("Destroyed", LogType::WARNING);
    }


    void GameObject::draw(OnDrawEvent& e){
        if(!m_IsVisible) 
            return;
        e.spriteRenderer->drawSprite(*m_Texture, m_Position, m_Size, m_Color);
    }

    void GameObject::update(OnUpdateEvent& e){
        if(m_Components.empty())
            return;

        for(int i = 0; i<m_Components.size(); i++){
            m_Components[i]->update();
        }
    }

    void GameObject::setParent(GameObject* parent){
        m_Parent = parent;
    }

    void GameObject::addChild(GameObject* child){
        child->setParent(this);
        m_Childrens.push_back(child);
    }

    void GameObject::removeAllChildren(){
        for(GameObject* child : m_Childrens){
             child->setIsAlive(false);
        }
        m_Childrens.clear();
    }


    


    std::shared_ptr<Texture> GameObject::getTexture(){
        return m_Texture;
    }

    void GameObject::setTexture(std::shared_ptr<Texture> texture){
        m_Texture = texture;
    }

    glm::vec2 GameObject::getPosition(){
        return m_Position;
    }

    void GameObject::setPosition(glm::vec2 position){
        m_Position = position;
    }

    float GameObject::getPositionX(){
        return m_Position.x;
    }

    void GameObject::setPositionX(float x){
        m_Position.x = x;
    }

    float GameObject::getPositionY(){
        return m_Position.y;
    }

    void GameObject::setPositionY(float y){
        m_Position.y = y;
    }

    glm::vec2 GameObject::getSize(){
        return m_Size;
    }

    void GameObject::setSize(glm::vec2 size){
        m_Size = size;
    }

    glm::vec3 GameObject::getColor(){
        return m_Color;
    }

    void GameObject::setColor(glm::vec3 color){
        m_Color = color;
    }

    bool GameObject::getIsAlive(){
        return m_IsAlive;
    }

    void GameObject::setIsAlive(bool isAlive){
        m_IsAlive = isAlive;
    }

    bool GameObject::getIsActive(){
        return m_IsActive;
    }

    void GameObject::setIsActive(bool isActive){
        m_IsActive = isActive;
    }


    bool GameObject::getIsVisible(){
        return m_IsVisible;
    }

    void GameObject::setIsVisible(bool isVisible){
        m_IsVisible = isVisible;
    }

    std::string& GameObject::getName(){
        return m_Name;
    }
}