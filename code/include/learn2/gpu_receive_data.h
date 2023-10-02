

void gpu_receive_data(unsigned int* vbo, unsigned int* vao,
float* input_vertices, int input_numVertices) {
    // Generate Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    printf("vbo: %d\n", *vbo);

    // Bind the Vertex Array Object first
    glBindVertexArray(*vao);

    // Bind and set vertex buffer(s)
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    int data_size = input_numVertices * 3 * sizeof(float);
    glBufferData(GL_ARRAY_BUFFER,data_size , input_vertices, GL_STATIC_DRAW);

    // Configure vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //in ra kích thước của vbo ở gpu bằng glgetbufferparameter
    // int size;
    // glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    // cout << "size of vbo: " << size << endl;
    // Enable the attribute
    glEnableVertexAttribArray(0);

    // Unbind VAO and VBO
    glBindVertexArray(0);


    //clean up

    //free(input_vertices);
}
void gpu_received_data_with_element(
    unsigned int* vbo, unsigned int* vao,
    unsigned int* ebo,
    float* vertices,
    int numVertices,
    unsigned int* indices,
    int numIndices
    ) {
    // Generate Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);
    // Bind the Vertex Array Object first
    glBindVertexArray(*vao);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    // Calculate the size in bytes of the vertex data
    // Copy vertex data to the buffer
    int data_size = sizeof(float) * numVertices * 3;
    glBufferData(GL_ARRAY_BUFFER, data_size, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    int data_size_indices = sizeof(unsigned int) * numIndices * 3;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_size_indices, indices, GL_STATIC_DRAW);

    // Configure vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
     glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
    // uncomment this call to draw in wireframe polygons.
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


}