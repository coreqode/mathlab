#include "vertex_buffer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace gl{

    void VertexBuffer::GenerateBuffers(const unsigned int &ID){
        glGenBuffers(ID, &this->vbo);
    }

    void VertexBuffer::BindBuffer(){
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    }

    void VertexBuffer::UnbindBuffer(){
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::BufferData(const float vertices[], const int size){
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

}
