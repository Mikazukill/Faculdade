#ifndef CONTA_HPP

class Conta {
    private:
        int numero;
        double saldo;
    public:
        Conta(int n = 0, double s = 0.0);
        int obtemNumero();
        double obtemSaldo();
        void depositar(double valor);
        void sacar(double valor);
        void sacar();
};

Conta::Conta(int n, double s) {
    numero = n;
    saldo = s;
}
int Conta::obtemNumero() {
    return numero;
}
double Conta::obtemSaldo() {
    return saldo;
}
void Conta::depositar(double valor){
    saldo = saldo + valor;
}
void Conta::sacar(double valor) {
    if(saldo >= valor) {
        saldo = saldo - valor;
    }
}
void Conta::sacar(){
    saldo = 0;
}

#endif