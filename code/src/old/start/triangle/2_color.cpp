#include<standard_includes.h>
#include<learn2/simple_shader.h>
#include<learn2/geometry_sets.h>
#include<learn2/gpu_receive_data.h>
#include<learn2/yellow_shader.h>
int main()
{
  
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    GLFWwindow* window=  init_glfw();
    unsigned int shaderProgram = simpleShader();
    unsigned int yellowShaderProgram = yellowShader();
        float vertices1[] = {
             -0.65f, -0.513f, 0.0f, // Đỉnh 1
    0.243f, -0.51f, 0.0f,  // Đỉnh 2
    0.0f,  0.8f, 0.0f,    // Đỉnh 3

    // -0.312f, 0.889f, 0.0f, // Đỉnh 4
    // 0.38f, 0.1f, 0.0f,    // Đỉnh 5
    // 0.12f, 0.254f, 0.0f,  // Đỉnh 6

    // Thêm các đỉnh khác để định nghĩa hình dạng phức tạp hơn
    // Ví dụ:
    // -0.5f, 0.9f, 0.0f,    // Đỉnh 7
    // 0.0f, 0.0f, 0.0f,    // Đỉnh 8
    // 0.7f, -0.3f, 0.0f,    // Đỉnh 9

        };
        float second_vertices[] = {
            //vẽ 3 đỉnh khác 3 đỉnh ở trên
            -0.5f, 0.9f, 0.0f,    // Đỉnh 7
            0.0f, 0.0f, 0.0f,    // Đỉnh 8
            0.7f, -0.3f, 0.0f,    // Đỉnh 9
        };

        int numVertices1 = sizeof(vertices1) / sizeof(vertices1[0]);
        int numSecondVertices = sizeof(second_vertices) / sizeof(second_vertices[0]);
        unsigned int VBO[2], VAO[2];
         gpu_receive_data(&VBO[0], &VAO[0], vertices1, numVertices1);
        gpu_receive_data(&VBO[1], &VAO[1],second_vertices, numSecondVertices);    

    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Xóa màn hình thành màu xanh dương
        glClear(GL_COLOR_BUFFER_BIT); // Xóa màn hình

        // Render logic (vẽ đối tcượng OpenGL ở đây)
        glUseProgram(shaderProgram);

         glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, numVertices1);
     //muốn cho tam giác 2 này màu khác thì phải tạo shader mới
         glUseProgram(yellowShaderProgram);
       

         glBindVertexArray(VAO[1]);
         glDrawArrays(GL_TRIANGLES, 0, numSecondVertices);
        



        // Swap buffers và xử lý sự kiện
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2,VBO);
    glDeleteProgram(shaderProgram);
    glDeleteProgram(yellowShaderProgram);
	glfwTerminate();
    return 0;
}

