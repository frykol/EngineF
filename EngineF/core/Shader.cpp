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
        std::string vertexString = readShader(m_VertexPath);
        std::string fragmentString = readShader(m_FragmentPath);

        const char* vertexSource = vertexString.c_str();
        const char* fragmentSource = fragmentString.c_str();

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
        glUseProgram(0);
    }

    std::string Shader::readShader(const char* shaderPath){
        std::ifstream file(shaderPath);
        std::string line;
        std::string shaderSource;
        while(std::getline(file, line)){
            shaderSource.append(line + "\n");
        }
        return shaderSource;
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



    void Shader::setUniform3f(const char* uniformName, float f1, float f2, float f3){
        bind();
        glUniform3f(glGetUniformLocation(m_ID, uniformName), f1, f2, f3);
    }   


    void Shader::setUniformMat4(const char* uniformName, glm::mat4& matrix){
        bind();
        glUniformMatrix4fv(glGetUniformLocation(m_ID, uniformName),1,false, glm::value_ptr(matrix));

    }
}