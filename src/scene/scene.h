#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../shader/shader.h"

namespace gl{
   
    namespace primitive{

        enum primT{
           line=GL_LINES, 
           triangle=GL_TRIANGLES
        };

    } //inner namepspace close

    class Scene{
        public:
            Scene();
            bool init(const int = 800, const int = 600);
            inline bool should_close();
            inline void swap_buffers();
            void render(Shader &sh, gl::primitive::primT line_type, float color[4], const char* loc);
        
        private:
            GLFWwindow *main_window;
    };

} //namespace ending




#endif
