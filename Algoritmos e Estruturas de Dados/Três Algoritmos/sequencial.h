int sequencial (int vet[], int n, int element ) {
    for(int i = 0; i < n; i++){
        if(vet[i] == element){
           return i; 
        }
    }
    return -1;
}