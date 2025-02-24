#include "Font.h"
#include "../Logger.h"

#include "ft2build.h"
#include FT_FREETYPE_H

namespace EngineF{
    Font::Font(const std::string& fontPath): m_Error(false){
        init(fontPath);
    }

    void Font::init(const std::string& fontPath){
        if(FT_Init_FreeType(&m_Library)){
            LOG("Could not init FreeType Library", LogType::ERROR);
            m_Error = true;
            return;
        }
        if (FT_New_Face(m_Library, fontPath.c_str(), 0, &m_Face))
        {
            LOG("ERROR::FREETYPE: Failed to load font", LogType::ERROR);
            m_Error = true;
            return;
        }
        FT_Set_Pixel_Sizes(m_Face, 0, 48); 
    }

    void Font::createFont(){
        if(m_Error){
            LOG("Can't create Font", LogType::ERROR);
            return;
        }
        for(unsigned char c = 0; c< 128; c++){

            if (FT_Load_Char(m_Face, c, FT_LOAD_RENDER)){
                    LOG("ERROR::FREETYPE: Failed to load Glyph", LogType::ERROR);
                    continue;
            }
            Character ch = {
                Texture(),
                glm::ivec2(m_Face->glyph->bitmap.width, m_Face->glyph->bitmap.rows),
                glm::ivec2(m_Face->glyph->bitmap_left, m_Face->glyph->bitmap_top),
                static_cast<unsigned int>(m_Face->glyph->advance.x)
            };
            ch.texture.createFontTexture(m_Face);
            m_Characters.emplace(c, ch);
        }
        FT_Done_Face(m_Face);
        FT_Done_FreeType(m_Library);
    }


    Character& Font::getCharacter(char c){
        if(m_Characters.find(c) != m_Characters.end())
            return m_Characters[c];
        return m_Characters[0];
    }
}
