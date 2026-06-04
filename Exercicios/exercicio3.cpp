#include <iostream>

using namespace std;

int main() {

    int a = 0;

    cout << "digite qual tabuada você quer: " << endl;
    cin >> a;
    
    for(int i = 0; i <= 10; i++) {
        int resultado = i * a;
        cout << "" << a << " X " << "" << i << " = " << "" << resultado << endl;
    }

    return 0;
}