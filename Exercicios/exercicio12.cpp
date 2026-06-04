#include <iostream>
#include <string>

using namespace std;

class Produto {
    private:
        string nome;
        double preco;
        int estoque;
    public:
        Produto(string n = "banana", double p = 5, int e = 0) {
            nome = n;
            preco = p;
            estoque = e;
        }
        int obtemEstoque() {
            cout << "estoque total: " << estoque << endl;
            return estoque;
        }
        double obtemPreco() {
            cout << "R$ " << preco << endl; 
            return preco;
        }
        int vender(int q) {
            if(estoque >= q) {
                estoque = estoque - q;
                cout << "compra finalizada" << endl;
                return estoque;
            } else {
                cout << "faltaram itens, temos apenas: " << estoque << endl;
                estoque = 0;
                return estoque;
            }
        }

        int comprar(int q) {
            estoque = estoque + q;
            return estoque;
        }
};

int main() {

    Produto prod1("Azeite", 7, 0);
    prod1.obtemPreco();
    prod1.vender(5);
    prod1.comprar(10);
    prod1.obtemEstoque();
    prod1.vender(5);
    prod1.vender(6);
    
    return 0;
}