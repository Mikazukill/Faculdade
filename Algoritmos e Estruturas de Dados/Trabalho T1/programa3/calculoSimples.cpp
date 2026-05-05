#include <iostream>

using namespace std;

int main () {

    int id;
    double preco;
    int quantia;

    cin >> id;
    cin >> preco;
    cin >> quantia;

    double valor = quantia * preco;

    cout << "" << valor << endl;
    
    return 0;
}