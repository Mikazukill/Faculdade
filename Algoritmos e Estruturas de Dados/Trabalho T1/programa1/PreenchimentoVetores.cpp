#include <iostream>

using namespace std;

int main () {
    int numero;
    int vecImpar[5];
    int vecPar[5];
    int NumVecPar = 0;
    int NumVecImpar = 0;

    for (int i = 0; i < 15; i++) {

        cin >> numero;

        if ((numero % 2) == 0) {
            vecPar[NumVecPar] = numero;
            NumVecPar++;

            if (NumVecPar == 5) {
                NumVecPar = 0;
                for (int j = 0; j < 5; j++) {
                    cout << "par[" << j << "] = " << vecPar[j] << endl;
                }
            }
        } 
        
        else {
            vecImpar[NumVecImpar] = numero;
            NumVecImpar++;

            if (NumVecImpar == 5) {
                NumVecImpar = 0;
                for (int k = 0; k < 5; k++) {
                    cout << "impar[" << k << "] = " << vecImpar[k] << endl;
                }
            }
        }
    }

    for (int k = 0; k < 5; k++) {
        cout << "impar[" << k << "] = " << vecImpar[k] << endl;
    }

    for (int j = 0; j < 5; j++) {
        cout << "par[" << j << "] = " << vecPar[j] << endl;
    }
    
    return 0;
}