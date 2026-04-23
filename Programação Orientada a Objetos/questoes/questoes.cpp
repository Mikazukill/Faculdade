#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FACIL 0
#define MEDIA 1
#define DIFICIL 2

#define FALSO 0
#define VERDADEIRO 1

class Questao {
private:
  int nivel;
  string enunciado;
  int resposta;
public:
  Questao(int n=-1, string e="", int r=-1) {
    nivel = n;
    enunciado = e;
    resposta = r;
  }
  
  string str() const {
    stringstream ss;
    ss << enunciado << endl;
    if ( resposta )
       ss << "> VERDADEIRO" << endl;
    else
       ss << "> FALSO" << endl;
    return ss.str();
  }
  
  ifstream &le(ifstream &in) {
    int n, r;
    string linha, e;
    if ( !getline(in,linha) ) return in;
    n = stoi(linha);
    if ( !getline(in,e) ) return in;
    if ( !getline(in,linha) ) return in;
    r = stoi(linha);
    nivel = n;
    enunciado = e;
    resposta = r;
    return in;
  }
  
  bool aplica() const {
    cout << enunciado << endl;
    cout << "(V)erdadeiro" << endl;
    cout << "(F)also" << endl;
    string linha;
    int respUsuario = -1;
    while ( respUsuario == -1 ) {
      cout << "> ";
      getline(cin,linha);
      if ( linha=="V" || linha=="v" )
         respUsuario = 1;
      else if ( linha=="F" || linha=="f" )
         respUsuario = 0;
      else
         respUsuario = -1;
    }
    return respUsuario == resposta; 
  }
  
};

#define MAX_QUESTOES 200

class Questionario {
private:
  Questao questoes[MAX_QUESTOES];
  int numQuestoes;
public:
  Questionario();
  Questionario(string nomeArquivo);
  int aplica();
};

int main() {
  ifstream fin;
  
  fin.open("questoes.txt",ios::in);
  if ( !fin.is_open() ) {
     cerr << "> Impossível abrir o arquivo 'questoes.txt'..." << endl;
     return 1;
  }
  
  Questao q;
  int acertos = 0, questoes = 0;
  while ( q.le(fin) ) {
      ++ questoes;
      if ( q.aplica() )
         ++acertos;
      cout << endl;
      cout << "Questões: " << questoes << " - Acertos: " << acertos << endl << endl;
  }
  fin.close();
  return 0;
}
