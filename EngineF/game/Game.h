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
        std::shared_ptr<EngineF::SpriteRenderer> m_Renderer;
        EngineF::Scene* m_CurrentScene;



        float m_CurrentFrame;
        float m_DeltaTime;
        float m_LastFrame;

        float m_MaxFPS = 1.0f/60.0f;

        void update();


        void calculateDeltaTime();
        
    public:
        Game(int width, int height);
        void init();

        void handleInput();
};