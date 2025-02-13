#pragma once

#include <cstdlib>

#include "GL/glew.h"
#include "GLFW/glfw3.h"


#include "../Logger.h"

#include "../events/EventManager.h"
#include "../events/GameObjectEvents.h"
#include "../events/WindowEvents.h"

#include "glm/glm.hpp"

namespace EngineF{
    class Window{
        private:
            GLFWwindow* m_Window;

            ListenerID m_OnWindowResizeID;

            bool m_Init = false;

            int m_Width;
            int m_Height;

            glm::mat4 m_Projection;

            Window() = default;
            static Window* window;
        public:
            Window(const Window&) = delete;
            Window& operator=(const Window&) = delete;

            static Window& getInstance(){
                return *window;
            }


            void init(int width, int height);
            bool isRunning();


            void onWindowResize(OnWindowResizeEvent& e);

            void swapBuffers();
            int getWindowWidth();
            int getWindowHeight();

            glm::mat4& getProjection();
    };
    
}