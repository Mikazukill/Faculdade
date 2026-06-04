#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int banana = 5;
    int maca = 10;

    swap(&banana, &maca);

    cout << "" << banana << endl;
    cout << "" << maca << endl;
    
    return 0;
}