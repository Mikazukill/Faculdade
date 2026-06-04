#ifndef BANCO_HPP

#include <string>
#include "conta.hpp"

using namespace std;

const int MAX_CONTAS = 100;

class Banco {
    
    private:
        string nome;
        int numContas;
        Conta contas[MAX_CONTAS];
    public:
        void banco(string n) {
            nome = n;
        }
        string obtemNome()
        int obtemConta()

};

#endif