#include <iostream>

using namespace std;

int main () {

    int a;
    int b;
    int c;

    cin >> a;
    cin >> b;
    cin >> c;

    int menor = (a + b + abs(a - b)) / 2;
    int maior = (menor + c + abs(menor - c)) / 2;

    cout << "" << maior << endl; 

    return 0;
}