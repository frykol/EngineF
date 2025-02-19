#pragma once

#include "Window.h"
#include "../scene/Scene.h"

namespace EngineF{
    class Application{ 
        private:
            Window* m_Window;
            Scene* m_Scene;

            Application() = default;
            static Application* s_Application;
        public:
            Application(const Application&) = delete;
            Application& operator=(const Application&) = delete;

            static Application& getInstance(){
                return *s_Application;
            }

            void init(int width, int height);
            void run();
            Scene* getCurrentScene();
            Input& getInput();
    };
}