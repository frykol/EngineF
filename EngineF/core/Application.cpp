#include "Application.h"
#include "Timer.h"

namespace EngineF{
    void Application::init(int width, int height){
        m_Window = new Window();
        m_Window->init(width, height);
        m_Scene = new Scene("basic");
        m_Scene->testScene();
    }

    void Application::run(){
        Timer timer;
        EngineF::OnUserInitEvent onUserInitEvent(m_Scene);
        EngineF::EventManager::getInstance().dispatchEvent(onUserInitEvent);


        while(m_Window->isRunning()){
            timer.update();
            m_Window->update();
            if(timer.getDeltaTime() >= 1.0f){
                
                EngineF::OnUpdateEvent onUpdate;
                EngineF::EventManager::getInstance().dispatchEvent(onUpdate);

                EngineF::OnUserUpdateEvent onUserUpdate;
                EngineF::EventManager::getInstance().dispatchEvent(onUserUpdate);

                m_Scene->destroyNotAliveGameObjects();

                timer.resetDeltaTime();
            }
        }
    }

    Scene* Application::getCurrentScene(){
        return m_Scene;
    }

    Input& Application::getInput(){
        return m_Window->getInput();
    }
}

EngineF::Application* EngineF::Application::s_Application = new Application;