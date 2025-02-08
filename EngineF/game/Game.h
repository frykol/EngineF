#pragma once

#include <memory>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "core/Shader.h"
#include "core/Texture.h"
#include "core/SpriteRenderer.h"

class Game{
    private:
        std::shared_ptr<EngineF::SpriteRenderer> m_Renderer;
    public:
        Game();
        void init();
        void update();
    };