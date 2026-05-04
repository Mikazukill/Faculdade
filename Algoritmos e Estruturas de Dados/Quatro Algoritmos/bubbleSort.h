void bubbleSort (int vet[],int n) {
    int aux, i, j;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}