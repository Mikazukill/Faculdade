#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(NULL));

    int vet[10];
    int total = 0;

    for(int i = 0; i < 10; i++){
        vet[i] = rand();
    }
    for(int j = 0; j < 10; j++){
        total = total + vet[j];
    }

    cout << "TOTAL: " << "" << total << endl;

    return 0;
}