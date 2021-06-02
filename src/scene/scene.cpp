#include "scene.h"

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

inline void Scene::swap_buffers(){
        glfwSwapBuffers(this->main_window);
}
inline bool Scene::should_close(){
    return glfwWindowShouldClose(this->main_window) ;
}


void Scene::render(Shader &sh, array_type line_type, float color[4], const char* loc){
    while(!this->should_close()){
        glfwPollEvents();
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        sh.use();
        int vertex_color_location = glGetUniformLocation(sh.get_id(), loc);
        glUniform4f(vertex_color_location, color[0], color[1], color[2], color[3]);
        glDrawArrays(line_type, 0, 2);
        
        this->swap_buffers();
    }
}

