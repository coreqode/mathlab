#include "scene.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

Scene::Scene(){
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

bool Scene::init(const int WIDTH, const int HEIGHT ){
    main_window = glfwCreateWindow(WIDTH, HEIGHT, "Test Scene", NULL, NULL);

    if (!main_window){
        printf("GLFLW window creation is failed");
        glfwTerminate();
        return true;
    }

    glfwMakeContextCurrent(main_window);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK){
        printf("GLEW initialization failed");
        glfwDestroyWindow(main_window);
        glfwTerminate();
        return true;
    }
    return true;
}

void Scene::swap_buffers(){
        glfwSwapBuffers(this->main_window);
}
bool Scene::should_close(){
    return glfwWindowShouldClose(this->main_window) ;
}
