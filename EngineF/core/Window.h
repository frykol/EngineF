#pragma once

#include <cstdlib>

#include "GL/glew.h"
#include "GLFW/glfw3.h"


#include "../Logger.h"

#include "../events/EventManager.h"
#include "../events/KeyPressEvent.h"

namespace EngineF{
    class Window{
        private:
            GLFWwindow* m_Window;
            float m_Width;
            float m_Height;

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