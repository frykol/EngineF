#pragma once 

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../Logger.h"

namespace EngineF{
    class Shader{
        private:
            unsigned int m_ID;

            int m_Status = -1;

            const char* m_Name;
            const char* m_VertexPath;
            const char* m_FragmentPath;
            

            const char* readShader(const char* shaderPath);
            void createShader();

            bool doesFileExist(const char* filepath);

        public:
            Shader(const char* vertexPath, const char* fragmentPath, const char* name = "null");

            void bind();
            void unBind();
            const char* getName(){return m_Name; }
            void setName(const char* name) {m_Name = name; }
    };
}