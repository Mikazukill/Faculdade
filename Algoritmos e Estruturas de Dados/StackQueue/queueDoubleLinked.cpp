#include "queueDoubleLinked.h"
#include <iostream>
#include <string>

using namespace std;

QueueDoubleLinked::QueueDoubleLinked() {
    data = new ListDoubleLinked;
    count = 0;
}

void QueueDoubleLinked::enqueue(int element) {
    data->add(element);
    count++;
}

int QueueDoubleLinked::head() {
    int valor = data->get(0);
    return valor;
}

int QueueDoubleLinked::dequeue() {
    int valor = data->get(0);
    data->remove(0);
    count--;
    return valor;
}

string QueueDoubleLinked::toString() {
    string valor = data->toString();
    return valor;
}

void QueueDoubleLinked::clear(){
    data->clear();
}

bool QueueDoubleLinked::isEmpty() {
    return data->isEmpty();
}

int QueueDoubleLinked::size() {
    return data->size();
}

int main () {

    QueueDoubleLinked lista;

    cout << "vazio?" << lista.isEmpty() << endl;
    lista.enqueue(5);
    cout << "conteúdo da lista: " << lista.toString() << endl;
    cout << "tamanho da lista: " << lista.size() << endl;
    cout << "ainda vazio?" << lista.isEmpty() << endl;
    cout << "primeiro da lista: " << lista.head() << endl;
    lista.enqueue(10);
    lista.enqueue(15);
    cout << "conteúdo da lista: " << lista.toString() << endl;
    cout << "tamanho da lista: " << lista.size() << endl;
    cout << "primeiro da lista: " << lista.head() << endl;
    cout << "valor removido: " << lista.dequeue() << endl;
    cout << "conteúdo da lista: " << lista.toString() << endl;
    cout << "tamanho da lista: " << lista.size() << endl;
    cout << "primeiro da lista: " << lista.head() << endl;
    lista.clear();
    cout << "vazio?" << lista.isEmpty() << endl;

    return 0;
}