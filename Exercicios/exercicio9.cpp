#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;
        string profissao;
    public:
        Pessoa(string n = "Fulano", int i = 18, string p = "desempregado") {
            nome = n;
            idade = i;
            profissao = p;
        }
        string obtemNome() {
            return nome;
        }
        int obtemIdade() {
            return idade;
        }
        string obtemProfissao() {
            return profissao;
        }
        void apresentar() {
            cout << "Nome: " << obtemNome() << endl;
            cout << "Idade: " << obtemIdade() << endl;
            cout << "Profissão: " << obtemProfissao() << endl;
        }
};

int main() {

    Pessoa pessoa1("Gabriel", 20, "Desenvolvedor");
    pessoa1.apresentar();
    Pessoa pessoa2("Emilly", 20, "Designer");
    pessoa2.apresentar();

    return 0;
}