#include <iostream>
#include <sstream>
#include "stringList.h"

using namespace std;

int main () {

    StringList lista;

    lista.add("Gabriel");
    lista.add("Emilly");

    cout << lista.str() << endl;

    ~StringList lista;

    lista.add("joão");
    lista.add("Yasmin");
    lista.add("Brenda");

    cout << lista.str() << endl;
    
    return 0;
}