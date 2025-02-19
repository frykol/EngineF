#include "Input.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Window.h"

namespace EngineF{
    void Input::init(){
        if(!m_Window->isInitialized()){
            LOG_E("Window is not initialized", LogType::ERROR, true);
            return;
        }

        m_KeyPressedID = EventManager::getInstance().addListener<KeyPressEvent>([this](KeyPressEvent& e){
            this->setKey(e);
        });

        glfwSetKeyCallback(m_Window->getWindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods){
            KeyPressEvent keyPressEvent(key, action);
            EventManager::getInstance().dispatchEvent(keyPressEvent);
        });

    }
    void Input::setKey(KeyPressEvent& e){
        if(e.action == GLFW_PRESS){
            m_KeyStates[e.keyCode] = true;
            m_KeyPressedThisFrame[e.keyCode] = true;
        } else if(e.action == GLFW_RELEASE){
            m_KeyStates[e.keyCode] = false;
            m_KeyPressedThisFrame[e.keyCode] = false;
        }
    }

    bool Input::isKeyPressed(int key){
        auto it = m_KeyStates.find(key);
        return it != m_KeyStates.end() && it->second;
    }

    bool Input::isKeyPressedOnce(int key){
        if (m_KeyPressedThisFrame.find(key) != m_KeyPressedThisFrame.end() && m_KeyPressedThisFrame[key]) {
            m_KeyPressedThisFrame[key] = false;  
            return true; 
        }
        return false;
    }

}