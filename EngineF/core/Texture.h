#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../stb_image/stb_image.h"

#include "../Logger.h"

namespace EngineF{

    class Texture{
        private:
            int m_Status = -1;

            unsigned int m_ID;
            int m_Width;
            int m_Height;
            int m_NrChanels;

            const char* m_TexturePath;

            void createTexture();

        public:
            Texture(const char* texturePath);

            void bind();
            void unBind();
    };
}