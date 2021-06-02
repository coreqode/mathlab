#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vertex_buffer.h"

namespace gl{

        class VertexArray{
            public:
                VertexArray(){};
                void BindVertexArray();
                void GenVertexArray(const unsigned int &ID);
                void UnbindVertexArray();
                void DeleteVertexArray();
                void BindAttribute(const unsigned int &ID, VertexBuffer &buffer, const float vertices[], const int size);
            private:
                unsigned int vao;
        };

}
#endif


