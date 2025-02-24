#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../stb_image/stb_image.h"

#include "ft2build.h"
#include FT_FREETYPE_H

#include "../Logger.h"

namespace EngineF{

    class Texture{
        private:
            int m_Status = -1;

            unsigned int m_ID;
            int m_Width;
            int m_Height;
            int m_NrChanels;
            

        public:
            Texture();
            void createTexture(const char* texturePath);
            void createFontTexture(const FT_Face& face);
            void bind() const;
            void unBind() const;
    };
}