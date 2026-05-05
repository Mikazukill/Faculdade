#include <iostream>

using namespace std;

int main () {

    double valor;

    cin >> valor;

    if (valor >= 0 && valor <= 100) {
        if(valor < 50) {
            if(valor <= 25) {
                cout << "0,25" << endl;
            } else {
                cout << "25,50" << endl;
            }
        }
        else {
            if (valor <= 75){
                cout << "50,75" << endl;
            } else {
                cout << "75,100" << endl;
            }
        }
    } else {
        cout << "Fora de intervalo" << endl;
    }
    return 0;
}