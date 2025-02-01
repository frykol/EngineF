#pragma once
#include <iostream>
#include <functional>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace EngineF{
    #define GLLOG(x) GLLog(x, __FILE__, __LINE__)
    #define LOG(x,y) Log(#x, y, __FILE__, __LINE__)

    enum LogType{
        MESSAGE = 0,
        WARNING = 1,
        ERROR = 2
    };


    void GLLog(std::function<void()> func, const char* file, int line){
        while(glGetError() != GL_NO_ERROR);
        func();
        while(GLenum error = glGetError()){
            std::cout << "GL ERROR in: " << file << " At Line: " << line << " Error Code: " <<  error << std::endl;
        }
    }

    void Log(const char* message, LogType type, const char* file, int line){
        if(type == LogType::MESSAGE){
            std::cout << "\033[1;37m" << "[LOG MESSAGE]: "  << message << std::endl << "File: " <<file << std::endl << "Line: " << line << "\033[0m" << std::endl;
        }
        if(type == LogType::WARNING){
            std::cout << "\033[1;33m" << "[LOG WARNING]: "  << message << std::endl << "File: " <<file << std::endl << "Line: " << line << "\033[0m" << std::endl;
        }
        if(type == LogType::ERROR){
            std::cout << "\033[1;31m" << "[LOG ERROR]: "  << message << std::endl << "File: " <<file << std::endl << "Line: " << line << "\033[0m" << std::endl;
        }
    }
}