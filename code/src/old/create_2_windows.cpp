#include<standard_includes.h>

int main()
{
  
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
     GLFWwindow* window=  init_glfw();
     GLFWwindow* window2=  glfwCreateWindow(
        SCR_WIDTH, SCR_HEIGHT,
         "LearnOpenGL2", NULL, NULL);
    if (window2 == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
     glfwMakeContextCurrent(window2);
     //window3
        GLFWwindow* window3=  glfwCreateWindow(
            SCR_WIDTH, SCR_HEIGHT,
            "LearnOpenGL3", NULL, NULL);
        if (window3 == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
         glfwMakeContextCurrent(window3);
	 // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // Render logic (vẽ đối tượng OpenGL ở đây)

        // Swap buffers và xử lý sự kiện
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	//glfwTerminate();
    return 0;
}

