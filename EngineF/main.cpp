#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Logger.h"



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
    
    float data[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f, 0.5f 
    };

    unsigned int VAO;
    EngineF::GLLOG([&VAO]{glGenVertexArrays(1, &VAO);});
    //glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    EngineF::GLLOG([data]{glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);});

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
    glEnableVertexAttribArray(0);


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    EngineF::LOG(8, EngineF::LogType::MESSAGE);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);

        EngineF::GLLOG([]{glDrawArrays(GL_TRIANGLES, 0, 3);});

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    return 0;
}