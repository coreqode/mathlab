#ifndef SCENE_H
#define SCENE_H

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Scene{
    public:
        Scene();
        bool init(const int = 800, const int = 600);
        bool should_close();
        void swap_buffers();

    
    private:
        GLFWwindow *main_window;
};

#endif
