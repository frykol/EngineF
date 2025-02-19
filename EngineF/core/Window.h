#pragma once

#include <cstdlib>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "SpriteRenderer.h"

#include "../Logger.h"

#include "../events/EventManager.h"
#include "../events/GameObjectEvents.h"
#include "../events/WindowEvents.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace EngineF{
    class Input;
    class Window{
        private:
            GLFWwindow* m_Window;
            Input* m_Input;
            SpriteRenderer* m_SpriteRenerer;

            ListenerID m_OnWindowResizeID;

            bool m_Init = false;

            int m_Width;
            int m_Height;

            glm::mat4 m_Projection;

        public: 
            Window() {};
            ~Window();

            void init(int width, int height);
            void update();

            bool isRunning();
            void onWindowResize(OnWindowResizeEvent& e);

            void swapBuffers();
            int getWindowWidth();
            int getWindowHeight();

            bool isInitialized();

            GLFWwindow* getWindow();

            Input& getInput();

            glm::mat4& getProjection();
    };
    
}