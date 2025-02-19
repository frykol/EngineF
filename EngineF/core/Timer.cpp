#include "Timer.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace EngineF{
    Timer::Timer(): m_CurrentFrame(0), m_DeltaTime(0), m_MaxFPS(1.0f/60.0f), m_LastFrame(0){
        m_LastFrame = glfwGetTime();
    }

    void Timer::update(){
        m_CurrentFrame = glfwGetTime();
        m_DeltaTime += (m_CurrentFrame - m_LastFrame) / m_MaxFPS;
        m_LastFrame = m_CurrentFrame;
    }

    void Timer::setMaxFps(float maxFps){
        m_MaxFPS = maxFps;
    }
    float Timer::getDeltaTime(){
        return m_DeltaTime;
    }

    void Timer::resetDeltaTime(){
        m_DeltaTime--;
    }
}