#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

namespace gl{

    class VertexBuffer{
        public:
            VertexBuffer(){};
            void GenerateBuffers(const unsigned int &ID);
            void BindBuffer();
            void UnbindBuffer();
            void BufferData(const float vertices[], const int size);

        private:
            unsigned int vbo;
            
    };

}

#endif
