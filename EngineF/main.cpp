#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Logger.h"

#include "core/SpriteRenderer.h"
#include "core/Shader.h"

#include "glm/glm.hpp"



int main(int argc, char** argv){
    GLFWwindow* window;
    if (!glfwInit())
        exit(-1);


    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    EngineF::GLLOG([]{glewInit();});
    

    EngineF::Shader shader("./../../EngineF/shaders/basic.vertex", "./../../EngineF/shaders/basic.fragment", "basic");

    EngineF::SpriteRenderer* spriteRenderer = new EngineF::SpriteRenderer(shader);

    shader.setUniform3f("cl", 0.5f, 0.2f, 1.0f);

    glm::mat4 camera = glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f);

    shader.setUniformMat4("u_Projection", camera);


    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        spriteRenderer->drawSprite(glm::vec2(-100.0f,-100.0f), glm::vec2(400.0f, 200.0f), glm::vec3(1.0f,0.2f,0.2f));

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    return 0;
}