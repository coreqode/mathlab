#ifndef LINE_H
#define LINE_H

//#include "shape.h"

void create_line(const float vertices[], const int size,  VAO &vao, VBO &vbo){
    vao.gen_vertex_array();
    vao.bind_vertex_array();

    vbo.gen_buffers();
    vbo.bind_buffer();

    vbo.buffer_data(vertices,size);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    vbo.unbind_buffer();
    vao.unbind_vertex_array();
}

//class Line : public Shape{
//    public:
//        Line();
//        void draw(const  float x[],  const float y[]) override;
//
//    private:
//        const float pt1;
//        const float pt2;
//};


#endif
