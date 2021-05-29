#ifndef CREATE_TRIANGLE_H
#define CREATE_TRIANGLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../global.h"

unsigned int VBO;
void create_triangle(VAO &vao){
    vao.gen_vertex_array();
    vao.bind_vertex_array();

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    vao.unbind_vertex_array();
}

#endif
