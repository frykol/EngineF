#include "GameObject.h"

namespace EngineF{
    GameObject::GameObject(std::shared_ptr<Texture> texture, glm::vec2 position, glm::vec2 size, glm::vec3 color)
    :m_Texture(texture), m_Position(position), m_Size(size), m_Color(color)
    {

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
}