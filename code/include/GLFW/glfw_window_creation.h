#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(
    GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
    }

GLFWwindow* glfw_window_creation (int width, int height ){
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(
        width, height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,
     framebuffer_size_callback);
    return window;
}