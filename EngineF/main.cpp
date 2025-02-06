#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Logger.h"

#include "core/SpriteRenderer.h"
#include "core/Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"




int main(int argc, char** argv){
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
    
    glm::mat4 proj = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

    EngineF::Shader shader("./../../EngineF/shaders/basic.vertex", "./../../EngineF/shaders/basic.fragment", "basic");

    EngineF::SpriteRenderer* spriteRenderer = new EngineF::SpriteRenderer(shader);



    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        spriteRenderer->drawSprite();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    return 0;
}