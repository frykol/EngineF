#include "Window.h"

#include "Input.h"
#include "ResourceManager.h"

#include "../events/DrawEvent.h"

namespace EngineF{ 
    Window::~Window(){
        delete m_Input;
        delete m_SpriteRenerer;
    }

    void Window::init(int width, int height){
        if(m_Init)
            LOG("Window Already Initialized", LogType::WARNING);

        if (!glfwInit()){
            exit(-1);
        }
        m_Width = width;
        m_Height = height;
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        m_Window = glfwCreateWindow(width, height, "Sneaking Mouse", NULL, NULL);

        if (!m_Window)
            {
                LOG("ERROR", LogType::ERROR);
                glfwTerminate();
                exit(-1);
            }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glfwMakeContextCurrent(m_Window);

        m_OnWindowResizeID = EventManager::getInstance().addListener<OnWindowResizeEvent>([this](OnWindowResizeEvent& e){
            this->onWindowResize(e);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos){
            OnMouseMoveEvent onMouseMoveEvent(xpos, ypos);
            EventManager::getInstance().dispatchEvent(onMouseMoveEvent);
        });

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){
            OnWindowResizeEvent onWindowResizeEvent(width, height);
            EventManager::getInstance().dispatchEvent(onWindowResizeEvent);
        });

        glfwSwapInterval(1);

        glewInit();
        m_Projection = glm::ortho(0.0f,static_cast<float>(m_Width),static_cast<float>(m_Height),0.0f, -1.0f,1.0f);

        m_Input = new Input(this);
        

        std::shared_ptr<EngineF::Shader> shader = EngineF::ResourceManager::getInstance().loadShader("shaders/basic.vertex","shaders/basic.fragment", "basic");
        m_SpriteRenerer = new SpriteRenderer(*shader);
        glm::mat4 view = glm::mat4(1.0f);
        shader->setUniformMat4("u_View", view);
        shader->setUniformMat4("u_Projection",getProjection());
    
        shader->unBind();
        m_Init = true;
        m_Input->init();
    }

    void Window::update(){
        m_SpriteRenerer->clear(glm::vec3(0.3f, 0.3f, 0.3f));
        EngineF::OnDrawEvent onDrawEvent(m_SpriteRenerer);
        EngineF::EventManager::getInstance().dispatchEvent(onDrawEvent);
        glfwPollEvents();
        swapBuffers();
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

    Input& Window::getInput(){
        return *m_Input;
    }
}
