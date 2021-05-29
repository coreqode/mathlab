#include <stdio.h>
#include <string.h>
#include <iostream>

#include "triangle.h"
#include "shader.h"
#include "scene.h"

const int WIDTH = 1200,  HEIGHT = 600;

int main(){
    Scene scene;
    scene.init();
    createTriangle();
    glBindVertexArray(VAO);
    Shader sh("./shader.vs", "./shader.fs");

    while(!scene.should_close()){
        glfwPollEvents();
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        sh.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        scene.swap_buffers();

    }

    return 0;
}

/* Pseudocode
 *
 * Initialize the scene
 * make the shape
 * Add the shape to the scene
 * Initialize the shader 
 * start the loop
 * Add mouse events
 */
