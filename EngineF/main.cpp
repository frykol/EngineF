#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Logger.h"

#include "core/SpriteRenderer.h"
#include "math/Vector2f.h"


int main(){
     GLFWwindow* window;
    if (!glfwInit())
        exit(-1);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    EngineF::GLLOG([]{glewInit();});
    
    EngineF::Vector2f one(1.0f,2.0f);
    EngineF::Vector2f two(2.0f,3.0f);

    EngineF::Vector2f three = one + two;

    EngineF::SpriteRenderer* spriteRenderer = new EngineF::SpriteRenderer();
    EngineF::LOG(three.first, EngineF::LogType::MESSAGE);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        spriteRenderer->DrawSprite();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    return 0;
}