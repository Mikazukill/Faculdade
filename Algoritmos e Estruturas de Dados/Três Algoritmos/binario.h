int binario (int vet[], int n, int element, int start, int end){
    if (start > end) {
        return -1;
    }

    int mid = (start + end)/2;

    if (vet[mid] == element) {
        return mid;
    }
    if(element > vet[mid]) {
        return binario (vet,n,element,mid + 1,end);
    } else {
        return binario (vet,n,element,start,mid - 1);
    }
}