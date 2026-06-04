#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(NULL));

    int vet[10];

    for(int i = 0; i < 10; i++) {
        vet[i] = rand() % 100;
        cout << "|" << "" << vet[i];
    }

    cout << "|" << endl;

    int maior = vet[0];
    int menor = vet[0];

    for(int j = 0; j < 10; j++) {
        if(maior < vet[j]) {
            maior = vet[j];
        }
        if(menor > vet[j]) {
            menor = vet[j];
        }
    }

    cout << "Maior: " << maior << endl;
    cout << "menor: " << menor << endl;

    return 0;
}