#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(NULL));

    int numero = rand() % 100;
    int resposta = -1;

    cout << "Adivinhe o número de 0 a 100: " << endl;
    cin >> resposta;

    while(resposta != numero) {
        if(resposta < numero) {
            cout << "o numero é maior" << endl;
        } else {
            cout << "o numero é menor" << endl;
        }
        cin >> resposta;
    }

    cout << "você acertou!" << endl;

    return 0;
}