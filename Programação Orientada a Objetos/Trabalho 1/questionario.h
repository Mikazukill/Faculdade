#include <string>
#include "questao.h"
#include <iostream>

using namespace std;

class questionario {
    private:
        int numquestoes;
        questao questoes[20];
    public:
        questionario() {
            numquestoes = 0;
        }
        void adicionaquestao(questao novaquestao) {
            if (numquestoes < 20) {
                questoes[numquestoes] = novaquestao;
                numquestoes = numquestoes + 1;
            } else {
                cout << "Aviso: Limite maximo de 20 questoes atingido." << endl;
            }
        }
};