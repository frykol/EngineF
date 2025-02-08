#pragma once

#include <memory>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../core/Shader.h"
#include "../core/Texture.h"
#include "../core/SpriteRenderer.h"
#include "../core/ResourceManager.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "../Logger.h"

class Game{
    private:
        GLFWwindow* m_Window;
        std::shared_ptr<EngineF::SpriteRenderer> m_Renderer;

        float m_Width;
        float m_Height;

        void update();

        void initOpenGl();
    public:
        Game(int width, int height);
        void init();
        
    };