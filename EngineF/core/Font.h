#pragma once

#include <memory>
#include <map>

#include "Texture.h"
#include "glm/glm.hpp"


namespace EngineF{
    struct Character{
        Texture texture;
        glm::ivec2 size;
        glm::ivec2 bearing;
        unsigned int advance;
    };

    class Font{
        private:
            FT_Library m_Library;
            FT_Face m_Face;

            std::map<char, Character> m_Characters;

            bool m_Error;

            void init(const std::string& fontPath);
        public:
            Font(const std::string& fontPath);
            void createFont();
            Character& getCharacter(char c);
    };
}
