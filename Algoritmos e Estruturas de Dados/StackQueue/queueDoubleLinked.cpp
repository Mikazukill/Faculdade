#include "queueDoubleLinked.h"
#include <iostream>

using namespace std;

QueueDoubleLinked::QueueDoubleLinked() {
    data = new ListDoubleLinked;
    count = 0;
}

void QueueDoubleLinked::enqueue(int element) {
    data->add(element);
    count++;
}

int QueueDoubleLinked::head(){
    int valor = data->get(0);
    return valor;
}



int main () {


    return 0;
}