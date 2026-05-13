#include <iostream>

int main () {

    int vec[10] = {0,2,3,7,1,7,4,8,9,5};

    for(int i = 0; i < 10; i++) {
        if(vec[i] > vec [i+1]) {
            int aux = vec[i];
            vec[i+1] = vec[i];
            vec[i] = aux;
        }
    }
    return 0;
}