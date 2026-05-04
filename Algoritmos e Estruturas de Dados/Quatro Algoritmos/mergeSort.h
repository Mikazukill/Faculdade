void mergeSort (int vet[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        
        mergeSort (vet, start, mid);
        mergeSort (vet, mid + 1, end);
    }
}

void merge (int vet[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int vet1[n1];
    int vet2[n2];

    for (int i = 0; i < n1; i++) {
        vet1[i] = vet[start + i];
    }

    for (int j = 0; j < n2; j++) {
        vet2[j] = vet[mid + 1 + j];
    }


}