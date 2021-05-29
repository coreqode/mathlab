#ifndef VBO_H
#define VBO_H

class VBO{
    public:
        VBO(){};
        void gen_buffers();
        void bind_buffer();

    private:
        unsigned int vbo;
        
};

#endif
