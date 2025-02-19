#pragma once

#include <memory>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../core/Window.h"

#include "../core/Shader.h"
#include "../core/Texture.h"
#include "../core/SpriteRenderer.h"




class Game{
    private:
        EngineF::Scene* m_CurrentScene;

        
    public:
        Game(int width, int height);
        void init();
};