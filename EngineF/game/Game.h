#pragma once

#include <memory>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../core/Shader.h"
#include "../core/Texture.h"
#include "../core/SpriteRenderer.h"
#include "../core/ResourceManager.h"

#include "../events/EventManager.h"
#include "../events/KeyPressEvent.h"

#include "../scene/GameObject.h"
#include "../scene/Scene.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../Logger.h"

class Game{
    private:
        GLFWwindow* m_Window;
        std::shared_ptr<EngineF::SpriteRenderer> m_Renderer;
        EngineF::Scene* m_CurrentScene;

        EngineF::ListenerID m_KeyID;

        float m_Width;
        float m_Height;

        float m_CurrentFrame;
        float m_DeltaTime;
        float m_LastFrame;

        float m_MaxFPS = 1.0f/60.0f;

        void update();

        void initOpenGl();

        void calculateDeltaTime();
        
    public:
        Game(int width, int height);
        void init();

        void handleInput(int key, int scancode, int action, int mods);

        void handleInputTest(EngineF::KeyPressEvent& e);
};