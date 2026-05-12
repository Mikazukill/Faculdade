int somaVector(int vec[], int count) {
    if(count <= 0) {
        return 0;
    }
    return vec[count - 1] + somaVector(vec, count - 1);
}