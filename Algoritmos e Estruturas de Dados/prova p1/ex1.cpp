int somaVetor(int vec[], int count) {

    if(count <= 0) {
        return 0;
    }
    return vec[count - 1] + somaVetor(vec, count - 1);
}