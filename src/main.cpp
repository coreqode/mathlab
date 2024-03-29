#include <stdio.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "util/vertex_array.h"
#include "util/vertex_buffer.h"
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
    gl::Scene scene;
    scene.init();

    //create line
    gl::VertexBuffer line_buffer;
    gl::VertexArray line;
    line.BindAttribute(1, line_buffer, vertices, sizeof(vertices));
    line.BindVertexArray();

    //if defined shader code 

    bool path = false;
    gl::Shader sh(v_shader_code, f_shader_code, path);

    //if shader code is defined in separate file
    //bool path = true;
    //scene.render("../src/data/shader.vs", "../src/data/shader.fs", path);
    
    //Render the scene
    float color[4] = {1.0f, 0.2, 0.3f, 0.0f};
    scene.render(sh, gl::primitive::line, color, "ourColor" );
    return 0;
}
