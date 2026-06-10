#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

using namespace std;

class Player {
    private:
        string nome;
        int tentativasTotais;
        int vezesJogadas;
    public:
        Player(string n = "", int t = 0, int v = 0) {
            nome = n;
            tentativasTotais = t;
            vezesJogadas = v;
        }
        string obtemNome() {
            return nome;
        }
        int obtemTentativasTotais() {
            return tentativasTotais;
        }
        int obtemVezesJogadas() {
            return vezesJogadas;
        }
        int obtemMediaTentativas() {
            if(vezesJogadas == 0) {
                return 0;
            }
            return tentativasTotais / vezesJogadas;
        }
        void partida(int tentativas) {
            tentativasTotais += tentativas;
            vezesJogadas++;
        }
};
#endif