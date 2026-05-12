// Arquivo: Exercicio001.cpp
// Autor: Gabriel Verissimo da Silva
// Finalidade: Implementacao da classe Hora com sobrecarga de operadores.
// Versao: 11/05/2026

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Hora {
private:
    int hora, minuto, segundo;

public:
    Hora();
    Hora(int h, int m, int s);
    ~Hora();

    int obtemHora() const;
    int obtemMinuto() const;
    int obtemSegundo() const;
    void defineHora(int h);
    void defineMinuto(int m);
    void defineSegundo(int s);
    string str() const;

    Hora operator+(const Hora &h); 

    friend ostream &operator<<(ostream &out, const Hora &h);
    friend istream &operator>>(istream &in, Hora &h);
};

Hora::Hora() {
    hora = 0;
    minuto = 0;
    segundo = 0;
}

Hora::Hora(int h, int m, int s) {
    hora = 0;
    minuto = 0;
    segundo = 0;
    defineHora(h);
    defineMinuto(m);
    defineSegundo(s);
}

Hora::~Hora() {
}

int Hora::obtemHora() const {
    return hora;
}

int Hora::obtemMinuto() const {
    return minuto;
}

int Hora::obtemSegundo() const {
    return segundo;
}

void Hora::defineHora(int h) {
    if(h >= 0 && h < 24) {
        hora = h;
    }
}

void Hora::defineMinuto(int m) {
    if (m >= 0 && m < 60) {
        minuto = m;
    }
}

void Hora::defineSegundo(int s) {
    if(s >= 0 && s < 60) {
        segundo = s;
    }
}

string Hora::str() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << hora << ":"
       << setfill('0') << setw(2) << minuto << ":"
       << setfill('0') << setw(2) << segundo;
    return ss.str();
}

Hora Hora::operator+(const Hora &h) {
    int s = segundo + h.obtemSegundo();
    int m = minuto + h.obtemMinuto() + (s / 60);
    int h_total = hora + h.obtemHora() + (m / 60);

    return Hora(h_total % 24, m % 60, s % 60);
}

ostream &operator<<(ostream &out, const Hora &h) {
    out << h.str();
    return out;
}

istream &operator>>(istream &in, Hora &h) {
    int tempHora, tempMinuto, tempSegundo;
    in >> tempHora >> tempMinuto >> tempSegundo;
    
    h.defineHora(tempHora);
    h.defineMinuto(tempMinuto);
    h.defineSegundo(tempSegundo);
    return in;
}

int main() {
    Hora h1, h2;
    cin >> h1;
    cin >> h2;

    Hora h3 = h1 + h2;
    cout << h3 << endl;

    return 0;
}
