#include <stdio.h>
#include <string.h>
#include <iostream>
//GLEW
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "global.h"
#include "triangle.h"
#include "shader.h"

int main(){
//Initialise the GLFW
    if ( !glfwInit() ){
        printf("GLFW initialisation failed");
        glfwTerminate();
        return 1;
    }
    
    //setup the GLFW window properties
    // OpenGl version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
    if (!mainWindow){
        printf("GLFLW window creation is failed");
        glfwTerminate();
        return 1;
    }

    //Set contxt for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    //Allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK){
        printf("GLEW initialization failed");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    createTriangle();
    glBindVertexArray(VAO);
    Shader sh("shader.vs", "shader.fs");

    while(!glfwWindowShouldClose(mainWindow)){
        glfwPollEvents();
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        sh.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(mainWindow);

    }

    return 0;
}
