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
        Hora operator+(const Hora &h1, const Hora &h2);
        friend ostream &operator<<(ostream &out, const Hora &h);
        friend istream &operator>>(istream &in, Hora &h);
};

// Implementação dos construtores e destrutor
Hora::Hora() : hora(0), minuto(0), segundo(0) {}

Hora::Hora(int h, int m, int s) : hora(h), minuto(m), segundo(s) {}

Hora::~Hora() {}

// Implementação dos getters
int Hora::obtemHora() const {
    return hora;
}

int Hora::obtemMinuto() const {
    return minuto;
}

int Hora::obtemSegundo() const {
    return segundo;
}

// Implementação dos setters
void Hora::defineHora(int h) {
    if (h >= 0 && h < 24)
        hora = h;
}

void Hora::defineMinuto(int m) {
    if (m >= 0 && m < 60)
        minuto = m;
}

void Hora::defineSegundo(int s) {
    if (s >= 0 && s < 60)
        segundo = s;
}

// Implementação do método str()
string Hora::str() const {
    stringstream ss;
    ss << setfill('0') << setw(2) << hora << ":"
       << setfill('0') << setw(2) << minuto << ":"
       << setfill('0') << setw(2) << segundo;
    return ss.str();
}

// Implementação dos operadores friend
ostream &operator<<(ostream &out, const Hora &h) {
    out << h.str();
    return out;
}

istream &operator>>(istream &in, Hora &h) {
    cout << "Digite hora: ";
    in >> h.hora;
    cout << "Digite minuto: ";
    in >> h.minuto;
    cout << "Digite segundo: ";
    in >> h.segundo;
    return in;
}

// Operador não membro de adição
Hora operator+(const Hora &h1, const Hora &h2) {
    int s = h1.obtemSegundo() + h2.obtemSegundo();
    int m = h1.obtemMinuto() + h2.obtemMinuto() + (s / 60);
    int h = h1.obtemHora() + h2.obtemHora() + (m / 60);
    
    return Hora(h % 24, m % 60, s % 60);
}

int main() {

    Hora h1, h2;
    cin >> h1;
    cin >> h2;
    Hora h3 = h1 + h2;
    cout << h3 << endl;

    return 0;
}
