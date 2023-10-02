#include<standard_includes.h>
#include<learn2/simple_shader.h>
#include<learn2/geometry_sets.h>
#include<learn2/gpu_receive_data.h>
#include <cmath>
#include<math.h>

const int numPoints = 20;
const float radius = 0.5f;
const float centerX = 0.0f;
const float centerY = 0.0f;
const float PI = 3.14159265358979323846f;
int main()
{
  
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    GLFWwindow* window=  init_glfw();
    unsigned int shaderProgram = simpleShader();
    
    float vertices[numPoints * 3]; // Mảng chứa tọa độ x, y, z cho mỗi điểm
    unsigned int indices[(numPoints-2) * 3];
    vertices[0] = centerX;
    vertices[1] = centerY;
    vertices[2] = 0.0f;
    for (int j = 0; j < numPoints-1; j++) {
        int i = j+1;
        float angle = 2.0f * PI * static_cast<float>(i) / static_cast<float>(numPoints-2);
        float x = centerX + radius * std::cos(angle);
        float y = centerY + radius * std::sin(angle);
        float z = 0.0f; // Độ sâu (z) có thể là 0

        // Lưu trữ tọa độ của điểm
        vertices[i * 3] = x;     // Tọa độ x
        vertices[i * 3 + 1] = y; // Tọa độ y
        vertices[i * 3 + 2] = z; // Tọa độ z
        if (j < numPoints - 1){
            indices[j * 3] = 0;
            indices[j * 3 + 1] = (j+1)%numPoints;
            indices[j * 3 + 2] = (j+2)%numPoints;
            };
    };
    

    unsigned int VBO, VAO, EBO;

    gpu_received_data_with_element(&VBO, &VAO,
     &EBO, vertices,numPoints,  indices,numPoints-2 );
    
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Xóa màn hình thành màu xanh dương
        glClear(GL_COLOR_BUFFER_BIT); // Xóa màn hình

        // Render logic (vẽ đối tượng OpenGL ở đây)
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 3*(numPoints-2), GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 0, numPoints);
        // Swap buffers và xử lý sự kiện
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1,&EBO);
    glDeleteProgram(shaderProgram);
	glfwTerminate();
    return 0;
}

