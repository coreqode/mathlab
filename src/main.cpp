#include <stdio.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "util/vao.h"
#include "util/vbo.h"
#include "math/triangle.h"
#include "math/line.h"
#include "scene/scene.h"

const char *v_shader_code = "                                      \n\
#version 330 core                                                   \n\
layout (location = 0) in vec3 aPos;                                 \n\
                                                                    \n\
void main(){                                                        \n\
    gl_Position = vec4(aPos, 1.0);                                  \n\
}                                                                   \n\
";

const char *f_shader_code = "                                      \n\
#version 330 core                                                   \n\
out vec4 FragColor;                                                 \n\
uniform vec4 ourColor;                                                   \n\
void main(){                                                    \n\
    FragColor = ourColor;                       \n\
}                                                                   \n\
";

int main(){
    //define vertices for the line
    const float vertices[] = {
        -1.0f, -0.3f, 0.0f, 
        0.9f, -1.0f, 0.0f, 
    };
    
    //Initialize the scene
    Scene scene;
    scene.init();

    //Initialize the VAO and VBO
    VAO vao;
    VBO vbo;
    
    //create line
    create_line(vertices, sizeof(vertices),  vao, vbo);

    //if defined shader code 
    bool path = false;
    vao.bind_vertex_array();
    Shader sh(v_shader_code, f_shader_code, path);

    //if shader code is defined in separate file
    //bool path = true;
    //scene.render("../src/data/shader.vs", "../src/data/shader.fs", path);
    
    //Render the scene
    float color[4] = {1.0f, 0.2, 0.3f, 0.0f};
    scene.render(sh, line, color, "ourColor" );
    return 0;
}
