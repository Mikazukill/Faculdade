#include <iostream>
#include "binario.h"
#include "sequencial.h"
#include "bubbleSort.h"

using namespace std;

int main () {

    int start = 0;
    const int n = 10;
    int end = n - 1;
    int vet[n] = {5, 2, 9, 1, 5, 6, 7, 3, 4, 8};
    int busca = 10;

    int resultadoSequencial = sequencial (vet, n, busca);

    if (resultadoSequencial == -1) {

          cout << "não encontrado de forma sequencial" << endl;

    } else {

          cout << "encontrado de forma sequencial na posição: " << resultadoSequencial << endl;

    }
    
    bubbleSort(vet,n);

    int resultadoBinario = binario (vet, n, busca,start,end);

    if (resultadoBinario == -1) {

        cout << "não encontrado de forma binaria" << endl;

    } else {

        cout << "encontrado de forma binaria na posição: " << resultadoBinario << endl;

    }
    
    return 0;
}