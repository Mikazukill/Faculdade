#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include "player.hpp"

using namespace std;

int main() {

    vector<Player> jogadores;
    
    ifstream leitura("jogadores.txt");

    string nome;
    cout << "Digite seu nome: " << endl;
    cin >> nome;
    
    SetConsoleOutputCP(CP_UTF8);

    srand(time(NULL));

    char jogarNovamente = 's';
    int vezes = 0;

    if(leitura.is_open()) {
        string nomeTemp;
        int tentativasTemp;
        int vezesTemp;
        while(leitura >> nomeTemp >> tentativasTemp >> vezesTemp) {
            Player temp(nomeTemp, tentativasTemp, vezesTemp);
            jogadores.push_back(temp);
        }
        leitura.close();
    }
    int numeroDeJogadores = jogadores.size();
    int indexJogador = -1;
    for(int i = 0; i < numeroDeJogadores; i++) {
        if(jogadores[i].obtemNome() == nome) {
            indexJogador = i;
            break;
        }
    }

    if(indexJogador == -1) {
        Player novo(nome);
        jogadores.push_back(novo);
        indexJogador = jogadores.size() - 1;
        cout << "Bem-vindo, novo jogador!" << endl;
    } else {
        cout << "Bem-vindo de volta, " << nome << "!" << endl;
        cout << "Suas estatísticas atuais: Vitórias: " << jogadores[indexJogador].obtemVezesJogadas() 
             << " | Média de tentativas: " << jogadores[indexJogador].obtemMediaTentativas() << endl;
    }

    while(jogarNovamente == 's' || jogarNovamente == 'S') {

    int numero = rand() % 100;
    int resposta = -1;

    cout << nome <<" Adivinhe o número de 0 a 100: " << endl;
    cin >> resposta;

    int tentativas = 1;
    
    while(resposta != numero) {
        if(resposta < numero) {
            cout << "o número é maior" << endl;
        } else {
            cout << "o número é menor" << endl;
        }
        tentativas++;
        cin >> resposta;
    }

    cout << "você acertou!" << endl;
    cout << "Número de tentativas: " << tentativas << endl;

    jogadores[indexJogador].partida(tentativas);

    cout << "Deseja jogar novamente? (s/n) " << endl;
    cin >> jogarNovamente;

    vezes++;

   }

   cout << "Obrigado por jogar!" << endl;

   if(vezes > 1) {
       cout << "você jogou: " << vezes << " vezes." << endl;
   } else {
       cout << "você jogou: " << vezes << " vez." << endl;
   }

   ofstream escrita("jogadores.txt");

   if(escrita.is_open()) {
       for(int i = 0; i < jogadores.size(); i++) {
           escrita << jogadores[i].obtemNome() << " " 
                   << jogadores[i].obtemTentativasTotais() << " " 
                   << jogadores[i].obtemVezesJogadas() << endl;
       }
       escrita.close();
   }

   system("pause");

    return 0;
}