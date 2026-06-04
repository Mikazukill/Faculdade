#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(NULL));

    int vet[10];
    int total = 0;

    for(int i = 0; i < 10; i++) {
        vet[i] = rand() % 100;
        total = total + vet[i];
    }
    int media = total / 10;

    for(int j = 0; j < 10; j++) {
        if(vet[j] > media) {
            cout << "" << vet[j] << endl;
        }
    }

    return 0;
}