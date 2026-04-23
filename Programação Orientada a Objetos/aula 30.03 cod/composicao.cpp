#include <iostream>
#include <iomanip>

using namespace std;

class Data {
private:
  int dia, mes, ano;
public:
  Data(int d=0, int m=0, int a=0) {
    dia = d;
    mes = m;
    ano = a;
    #ifdef DEBUG
    cerr << "+ Data(" << dia << "," << mes << "," << ano << ") criado..." << endl;
    #endif
  }
  ~Data() {
    #ifdef DEBUG
    cerr << "- Data(" << dia << "," << mes << "," << ano << ") destruído..." << endl;
    #endif
  }
  string str() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << dia << "/";
    ss << setfill('0') << setw(2) << mes << "/";
    ss << setfill('0') << setw(4) << ano;
    return ss.str();
  }
};

class Produto {
private:
  string nome;
  Data validade;
public:
  Produto(string n, Data &v) {
    nome = n;
    validade = v;
    #ifdef DEBUG
    cerr << "+ Produto(" << nome << "," << validade.str() << ") criado..." << endl;
    #endif
  }
  
  ~Produto() {
    #ifdef DEBUG
    cerr << "- Produto(" << nome << "," << validade.str() << ") destruído..." << endl;
    #endif
  }
};

int main() {
  Data d(30,3,2026);
  Produto p("produto 1", d);
  
  return 0;
}

