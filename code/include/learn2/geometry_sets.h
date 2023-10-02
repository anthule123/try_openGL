

float* triangle_vertex(int size){
    float* arr = (float*)calloc(size, sizeof(float));
    
    for (int i = 0; i < size; i++) {
        //random
        arr[i] = (float)rand() / RAND_MAX;
        cout<< "arr[i] size: "<<sizeof(arr[i])<<endl;
    };
    cout<< "array size: "<<sizeof(arr)<<endl;
    return arr;
}