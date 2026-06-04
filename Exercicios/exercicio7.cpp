#include <iostream>

using namespace std;

int func(int a = 0, int b = 0) {
    int resultado = a * b;

    return resultado;
}

int main() {

    int valor1 = 0;
    int valor2 = 0;

    cout << "digite um valor" << endl;
    cin >> valor1;
    cout << "digite outro valor" << endl;
    cin >> valor2;

    int total = func(valor1,valor2);
    
    cout << "" << valor1 << " X " << "" << valor2 << " = " << "" << total << endl;

    return 0;
}