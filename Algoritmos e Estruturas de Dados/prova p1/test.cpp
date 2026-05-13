#include <iostream>
#include "buscabinaria.h"

using namespace std;

int main () {
    
    int vec[10] = {1,2,3,4,5,6,7,8,9,10};
    int element;
    int start = 0;
    int end = 9;
    cout << "digite número buscado: " << endl;
    cin >> element;

    return Binario(vec, element, start, end);
}