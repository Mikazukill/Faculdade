#include <iostream>
#include <string>

using namespace std;

class Conta_Bancaria {
    private:
        int id;
        double saldo;
        string agencia;
    public:
        Conta_Bancaria(int i = 0, double s = 0.0, string a = "") {
            id = i;
            saldo = s;
            agencia = a;
        }
        int obtemId() {
            return id;
        }
        double obtemSaldo() {
            return saldo;
        }
        string obtemAgencia() {
            return agencia;
        }
        double deposito(double s) {
            if (s > 0){
                saldo = saldo + s;
                return saldo;
            } else {
                cout << "valor invalido" << endl;
                return saldo;
            }
        }
        double saque(double s) {
            if (s > 0) {
                if(s <= saldo + 100.0) {
                    saldo = saldo - s;
                } else {
                    cout << "saldo insuficiente" << endl;
                }
                return saldo;
            } else {
                cout << "valor invalido" << endl;
                return saldo;
            }
        }
        void saqueTotal() {
            saldo = -100;
        }
};

int main() {

    Conta_Bancaria conta1(6007, 500.5, "Banco do Brasil");
    conta1.deposito(499.5);
    conta1.saque(900);
    conta1.saqueTotal();
    conta1.saque(500);

    return 0;
}