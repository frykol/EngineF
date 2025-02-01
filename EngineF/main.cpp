#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"



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
    glewInit();

    while (!glfwWindowShouldClose(window))
    {
       glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    std::cout << "Hello" << std::endl;

    return 0;
}