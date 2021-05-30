#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../shader/shader.h"

class Scene{
    public:
        Scene();
        bool init(const int = 800, const int = 600);
        inline bool should_close();
        inline void swap_buffers();
        void render();
    
    private:
        GLFWwindow *main_window;
};

#endif
