#include <iostream>
#include <string>

using namespace std;

class Carro {
    private:
        string marca;
        string nome;
        int velocidade;
        bool ligado;
    public:
        Carro(string m = "Fiat", string n = "Mobi", int v = 0, bool l = false) {
            marca = m;
            nome = n;
            velocidade = v;
            ligado = l;
        }
        bool ligar() {
            if(ligado == false) {
                ligado = true;
                cout << "ligando" << endl;
                return ligado;
            } else {
                cout << "já está ligado" << endl;
                return ligado;
            }
        }
        bool desligar() {
            if(ligado == true && velocidade == 0) {
                ligado = false;
                cout << "desligando" << endl;
                return ligado;
            } else {
                cout << "já está desligado" << endl;
                return ligado;
            }
        }
        int acelerar(int v) {
            if(ligado == true) {
                velocidade = velocidade + v;
                cout << "velocidade atual: " << velocidade << endl;
                return velocidade;
            } else {
                cout << "ligue o carro primeiro" << endl;
                return velocidade;
            }
        }
        int frear(int v) {
            if(ligado == true && velocidade > 0) {
                if(velocidade >= v) {
                    velocidade = velocidade - v;
                    cout << "velocidade atual: " << velocidade << endl;
                    return velocidade;
                } else {
                    velocidade = 0;
                    cout << "velocidade atual: " << velocidade << endl;
                    return velocidade;
                }
            } else {
                cout << "valor invalido" << endl;
                return velocidade;
            }
        }
        int parar() {
            velocidade = 0;
            return velocidade;
        }
};

int main() {
    Carro carro1("Volkswagen", "Virtus", 0 , false);
    carro1.acelerar(60);
    carro1.ligar();
    carro1.acelerar(60);
    carro1.frear(20);
    carro1.parar();
    carro1.desligar();

    return 0;
}