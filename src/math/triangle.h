#ifndef CREATE_TRIANGLE_H
#define CREATE_TRIANGLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void create_triangle(const float vertices[], const int size,  VAO &vao, VBO &vbo){
    vao.gen_vertex_array();
    vao.bind_vertex_array();

    vbo.gen_buffers();
    vbo.bind_buffer();

    vbo.buffer_data(vertices,size);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    vbo.unbind_buffer();
    vao.unbind_vertex_array();
}

#endif
