#include <iostream>
#include <fstream>
#include <string>
#include "questao.h"
#include "questionario.h"

using namespace std;

int main () {

    ifstream arq("questoes10.txt");
        if (!arq.is_open()) {
            cout << "Não foi possivel abrir o arquivo" << endl;
            return 1;
        }
        while(getline(arq,string) != false) {
            string numquestoes;
            getline(arq, numquestoes);
            
        }
        
    return 0;
}