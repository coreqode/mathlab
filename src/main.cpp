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

const char *v_shader_code = "                                      \n\
#version 330 core                                                   \n\
layout (location = 0) in vec3 aPos;                                 \n\
layout (location = 1) in vec3 aColor;                               \n\
out vec3 ourColor;                                                  \n\
                                                                    \n\
void main(){                                                        \n\
    gl_Position = vec4(aPos, 1.0);                                  \n\
    ourColor = aColor;                                              \n\
}                                                                   \n\
";

const char *f_shader_code = "                                      \n\
#version 330 core                                                   \n\
out vec4 FragColor;                                                 \n\
in vec3 ourColor;                                                   \n\
void main(){                                                    \n\
    FragColor = vec4(ourColor, 1.0);                                \n\
}                                                                   \n\
";

int main(){
    Scene scene;
    scene.init();
    VAO vao;
    VBO vbo;
    create_triangle(vertices, sizeof(vertices),  vao, vbo);
    vao.bind_vertex_array();
    //scene.render("../src/data/shader.vs", "../src/data/shader.fs", true);
    scene.render(v_shader_code, f_shader_code);
    return 0;
}
