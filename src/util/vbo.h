#ifndef VBO_H
#define VBO_H

class VBO{
    public:
        VBO(){};
        void gen_buffers();
        void bind_buffer();
        void unbind_buffer();
        void buffer_data(const float vertices[], const int size);

    private:
        unsigned int vbo;
        
};

void VBO::gen_buffers(){
    glGenBuffers(1, &this->vbo);
}

void VBO::bind_buffer(){
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
}

void VBO::unbind_buffer(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::buffer_data(const float vertices[], const int size){
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}


#endif
