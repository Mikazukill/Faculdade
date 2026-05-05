#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    int id1;
    double preco1;
    int quantia1;

    int id2;
    double preco2;
    int quantia2;

    cin >> id1;
    cin >> preco1;
    cin >> quantia1;

    cin >> id2;
    cin >> preco2;
    cin >> quantia2;

    double valor1 = quantia1 * preco1;
    double valor2 = quantia2 * preco2;
    double total = valor1 + valor2;

    cout << "" << total << endl;
    
    return 0;
}