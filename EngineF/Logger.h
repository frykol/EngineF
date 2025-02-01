#pragma once
#include <iostream>
#include <functional>
#include <any>
#include <string>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace EngineF{
    #define GLLOG(x) GLLog(x, __FILE__, __LINE__)
    #define LOG(x,y) Log(x, y, __FILE__, __LINE__)

    enum LogType{
        MESSAGE = 0,
        WARNING = 1,
        ERROR = 2
    };


    inline void GLLog(std::function<void()> func, const char* file, int line){
        while(glGetError() != GL_NO_ERROR);
        func();
        while(GLenum error = glGetError()){
            std::cout << "GL ERROR in: " << file << " At Line: " << line << " Error Code: " <<  error << std::endl;
        }
    }

    inline std::string CastToString(std::any value){
        if(value.type() == typeid(const char*))
               return std::string(std::any_cast<const char*>(value));
         if(value.type() == typeid(std::string))
            return std::any_cast<std::string> (value);
    
        if (value.type() == typeid(float))
            return std::to_string(std::any_cast<float> (value));
    
        if (value.type() == typeid(int))
            return std::to_string(std::any_cast<int> (value));
        return "Type not supported";
    }

    inline void Log(std::any message, LogType type, const char* file, int line){
        std::string msg = CastToString(message);
        if(type == LogType::MESSAGE){
            std::cout << "\033[1;37m" << "[LOG MESSAGE]: "  << msg << std::endl << "File: " <<file << std::endl << "Line: " << line << "\033[0m" << std::endl;
        }
        if(type == LogType::WARNING){
            std::cout << "\033[1;33m" << "[LOG WARNING]: "  << msg << std::endl << "File: " <<file << std::endl << "Line: " << line << "\033[0m" << std::endl;
        }
        if(type == LogType::ERROR){
            std::cout << "\033[1;31m" << "[LOG ERROR]: "  << msg << std::endl << "File: " <<file << std::endl << "Line: " << line << "\033[0m" << std::endl;
        }
    }
}