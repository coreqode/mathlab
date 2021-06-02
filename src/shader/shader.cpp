#include "shader.h"

namespace gl{

        Shader::Shader(const char* vertexPath, const char* fragmentPath, bool path){
        std::string vertexCode;
        std::string fragmentCode;
        if (path){
            std::ifstream vShaderFile;
            std::ifstream fShaderFile;

            vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            try{
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);
                std::stringstream vShaderStream, fShaderStream;

                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();

                vShaderFile.close();
                fShaderFile.close();

                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
            }
            catch(std::ifstream::failure e){
                std::cout << "ERROR::SHADER::ENTERED FILE PATH NOT SUCCESSFULLY READ" << std::endl;
            }
        }
        const char* vShaderCode(path ? vertexCode.c_str() : vertexPath);
        const char* fShaderCode(path ? fragmentCode.c_str() : fragmentPath);

        this->compile_shaders(vShaderCode, fShaderCode);
    }

    void Shader::compile_shaders(const char* vShaderCode, const char* fShaderCode){
        ID = glCreateProgram();

        if (!ID){
            std::cout << "ERROR::SHADER::ERROR CREATING SHADER PROGRAM";
            return ;
        }

        this->addShader(ID, vShaderCode, GL_VERTEX_SHADER);
        this->addShader(ID, fShaderCode, GL_FRAGMENT_SHADER);

        GLint result = 0;
        GLchar eLog[1024] = {0};

        glLinkProgram(ID);
        glGetProgramiv(ID, GL_LINK_STATUS, &result);

        if (! result){
            glGetProgramInfoLog(ID, sizeof(eLog), NULL, eLog);
            printf("Error linking program: '%s'\n", eLog);
        }

        glValidateProgram(ID);
        glGetProgramiv(ID, GL_VALIDATE_STATUS, &result);
        if (! result){
            glGetProgramInfoLog(ID, sizeof(eLog), NULL, eLog);
            printf("Error validating program: '%s'\n", eLog);
        }
    }

    void Shader::addShader(unsigned int program, const char* shaderCode, GLenum shaderType){
        unsigned int theShader = glCreateShader(shaderType);

        glShaderSource(theShader, 1, &shaderCode, NULL);
        glCompileShader(theShader);

        int result = 0;
        char eLog[1024] = {0};

        glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
        if (!result){
            glGetShaderInfoLog(program, sizeof(eLog), NULL, eLog);
            printf("Error compiling the %d shader: '%s'\n", shaderType, eLog);
            return ;
        }
        glAttachShader(program, theShader);
    }

    void Shader::use(){
        glUseProgram(this->ID);
    }

    unsigned int Shader::get_id(){
        return this->ID;
    }

    
} //namespace ending
