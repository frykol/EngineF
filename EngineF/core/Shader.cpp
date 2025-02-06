#include "Shader.h"
#include <fstream>
#include <string>

namespace EngineF{

    Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* name):
    m_VertexPath(vertexPath), m_FragmentPath(fragmentPath), m_Name(name)
    {
        createShader();
    }

    void Shader::createShader(){
        if(!doesFileExist(m_VertexPath)){
            LOG("Vertex file does not exist", LogType::ERROR);
            return;
        }
        if(!doesFileExist(m_FragmentPath)){
            LOG("Fragment file does not exist", LogType::ERROR);
            return;
        }
        const char* vertexSource = readShader(m_VertexPath);
        const char* fragmentSource = readShader(m_FragmentPath);

        unsigned int vertexShader;
        unsigned int fragmentShader;

        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);

        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);

        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertexShader);
        glAttachShader(m_ID, fragmentShader);
        glLinkProgram(m_ID);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        m_Status = 1;
    }

    const char* Shader::readShader(const char* shaderPath){
        std::ifstream file(shaderPath);
        std::string line;
        std::string shaderSource;
        while(std::getline(file, line)){
            
            shaderSource.append(line + "\n");
        }
        return shaderSource.c_str();
    }

    bool Shader::doesFileExist(const char* filepath){
        if(FILE *file = fopen(filepath, "r")){
            fclose(file);
            return true;
        }
        else{
        return false;
        }
    }

    void Shader::bind(){
        if(m_Status != 1){
            LOG_E("Shader cant be bind", LogType::ERROR, true);
            return;
        }
        glUseProgram(m_ID);
    }

    void Shader::unBind(){
        glUseProgram(0);
    }

}