#ifndef VAO_H
#define VAO_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VAO{
    public:
        VAO(){};
        void bind_vertex_array();
        void gen_vertex_array();
        void unbind_vertex_array();
        void delete_vertex_array();
    private:
        unsigned int vao;
};

void VAO::bind_vertex_array(){
    glBindVertexArray(this->vao) ;
}

void VAO::unbind_vertex_array(){
    glBindVertexArray(0) ;
}

void VAO::gen_vertex_array(){
    glGenVertexArrays(1, &this->vao);
}

#endif
