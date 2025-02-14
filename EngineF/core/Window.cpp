#include "Window.h"

namespace EngineF{ 
    void Window::init(int width, int height){
        if(m_Init)
            LOG("Window Already Initialized", LogType::WARNING);

        if (!glfwInit())
            exit(-1);

        m_Width = width;
        m_Height = height;
        m_Window = glfwCreateWindow(width, height, "Engine F", NULL, NULL);

        if (!m_Window)
            {
                glfwTerminate();
                exit(-1);
            }

        glfwMakeContextCurrent(m_Window);

        m_OnWindowResizeID = EventManager::getInstance().addListener<OnWindowResizeEvent>([this](OnWindowResizeEvent& e){
            this->onWindowResize(e);
        });

        // glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
        //     KeyPressEvent keyPressEvent(key, action);
        //     EventManager::getInstance().dispatchEvent(keyPressEvent);
        // });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos){
            OnMouseMoveEvent onMouseMoveEvent(xpos, ypos);
            EventManager::getInstance().dispatchEvent(onMouseMoveEvent);
        });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){
            OnWindowResizeEvent onWindowResizeEvent(width, height);
            EventManager::getInstance().dispatchEvent(onWindowResizeEvent);
        });

        GLLOG([]{glewInit();});
        m_Projection = glm::ortho(0.0f,static_cast<float>(m_Width),static_cast<float>(m_Height),0.0f, -1.0f,1.0f);

        m_Init = true;
    }


    void Window::onWindowResize(OnWindowResizeEvent& e){
        m_Width = e.width;
        m_Height = e.height;
        glViewport(0, 0, e.width, e.height);
        m_Projection = glm::ortho(0.0f,static_cast<float>(m_Width),static_cast<float>(m_Height),0.0f,-1.0f,1.0f);
    }

    bool Window::isRunning(){
        return !glfwWindowShouldClose(m_Window);
    }

    bool Window::isInitialized(){
        return m_Init;
    }

    void Window::swapBuffers(){
        glfwSwapBuffers(m_Window);
    }

    int Window::getWindowWidth(){
        return m_Width;
    }

    int Window::getWindowHeight(){
        return m_Height;
    }
    glm::mat4& Window::getProjection(){
        return m_Projection;
    }

    GLFWwindow* Window::getWindow(){
        if(!m_Init){
            LOG_E("Window is not initialized", LogType::ERROR, true);
            return nullptr;
        }
        return m_Window;
    }
}

EngineF::Window* EngineF::Window::window = new Window;