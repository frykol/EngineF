#pragma once

#include <cstdlib>

#include "GL/glew.h"
#include "GLFW/glfw3.h"


#include "../Logger.h"

#include "../events/EventManager.h"
#include "../events/GameObjectEvents.h"

namespace EngineF{
    class Window{
        private:
            GLFWwindow* m_Window;

            bool m_Init = false;

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

            void swapBuffers();
    };
    
}