class Conta {
    private:
        int numero;
        double saldo;
    public:
        Conta(int n = 0, double s = 0.0);
        int obtemNumero();
        double obtemSaldo();
        void depositar(int valor);
        void sacar(int valor);
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
void Conta::depositar(int valor){
    saldo = saldo + valor;
}
void Conta::sacar(int valor) {
    saldo = saldo - valor;
}
void Conta::sacar(){
    saldo = 0;
}