#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    string nome = "";
    int idade = 0;
    
    cout << "nome: " << endl;
    cin >> nome;
    cout << "idade: " << endl;
    cin >> idade;

    ofstream arquivo_saida("registro.txt");
    arquivo_saida << nome << endl;
    arquivo_saida << idade << endl;

    arquivo_saida.close();


    string nome_lido;
    int idade_lida;

    ifstream arquivo_entrada("registro.txt");
    arquivo_entrada >> nome_lido;
    arquivo_entrada >> idade_lida;
    
    cout << "" << nome_lido << endl;
    cout << "" << idade_lida << endl;

    arquivo_entrada.close();

    return 0;
}