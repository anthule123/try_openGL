#include<standard_includes.h>
#include<learn2/simple_shader.h>
#include<learn2/geometry_sets.h>
#include<learn2/gpu_receive_data.h>

int main()
{

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    GLFWwindow* window=  init_glfw();
    unsigned int shaderProgram = simpleShader();
        float vertices[] = {
    -0.65f, -0.513f, 0.0f, // Đỉnh 1
    0.243f, -0.51f, 0.0f,  // Đỉnh 2
    0.0f,  0.8f, 0.0f,    // Đỉnh 3

    -0.312f, 0.889f, 0.0f, // Đỉnh 4
    0.38f, 0.1f, 0.0f,    // Đỉnh 5
    0.12f, 0.254f, 0.0f,  // Đỉnh 6

    // Thêm các đỉnh khác để định nghĩa hình dạng phức tạp hơn
    // Ví dụ:
    -0.5f, 0.9f, 0.0f,    // Đỉnh 7
    0.0f, 0.0f, 0.0f,    // Đỉnh 8
    0.7f, -0.3f, 0.0f,    // Đỉnh 9
    // ...
};

        int numVertices = sizeof(vertices) / sizeof(vertices[0]);
        unsigned int VBO, VAO;
        gpu_receive_data(&VBO, &VAO, vertices, numVertices);
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Xóa màn hình thành màu xanh dương
        glClearc(GL_COLOR_BUFFER_BIT); // Xóa màn hình

        // Render logic (vẽ đối tượng OpenGL ở đây)
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINES, 0, numVertices);

        // Swap buffers và xử lý sự kiện
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
	glfwTerminate();
    return 0;
}

