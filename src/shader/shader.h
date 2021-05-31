#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
    public:
        unsigned int ID;
        Shader(const char* vertexPath, const char* fragmentPath, bool path);
        void compile_shaders(const char* vShaderCode, const char* fShaderCode);
        void addShader(unsigned int program, const char* shaderCode, GLenum shaderType);
        void use();
};
#endif
