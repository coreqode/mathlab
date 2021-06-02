#include "vertex_array.h"

namespace gl{

        void VertexArray::BindVertexArray(){
            glBindVertexArray(this->vao) ;
        }

        void VertexArray::UnbindVertexArray(){
            glBindVertexArray(0) ;
        }

        void VertexArray::GenVertexArray(const unsigned int &ID){
            glGenVertexArrays(ID, &this->vao);
        }

        void VertexArray::BindAttribute(const unsigned int &ID, VertexBuffer &buffer, const float vertices[], const int size){
            GenVertexArray(ID);
            BindVertexArray();
            buffer.GenerateBuffers(1);
            buffer.BindBuffer();
            buffer.BufferData(vertices, size);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            buffer.UnbindBuffer();
            UnbindVertexArray();
        }

} //namespace closing
