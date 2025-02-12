#include "Window.h"

namespace EngineF{ 
    void Window::init(int width, int height){
        if(m_Init)
            LOG("Window Already Initialized", LogType::WARNING);

        if (!glfwInit())
            exit(-1);

    m_Window = glfwCreateWindow(width, height, "Engine F", NULL, NULL);

    if (!m_Window)
        {
            glfwTerminate();
            exit(-1);
        }

    glfwMakeContextCurrent(m_Window);

    LOG("OOO", LogType::MESSAGE);
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
        KeyPressEvent keyPressEvent(key, action);
        EventManager::getInstance().dispatchEvent(keyPressEvent);
    });

    GLLOG([]{glewInit();});


    m_Init = true;
    }

    bool Window::isRunning(){
        return !glfwWindowShouldClose(m_Window);
    }

    void Window::swapBuffers(){
        glfwSwapBuffers(m_Window);
    }
}

EngineF::Window* EngineF::Window::window = new Window;