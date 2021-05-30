#include <stdio.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "util/vao.h"
#include "util/vbo.h"
#include "math/triangle.h"
#include "scene/scene.h"

const float vertices[] = {
    -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f
};

int main(){
    Scene scene;
    scene.init();
    VAO vao;
    VBO vbo;
    create_triangle(vertices, sizeof(vertices),  vao, vbo);
    vao.bind_vertex_array();
    scene.render();
    return 0;
}
