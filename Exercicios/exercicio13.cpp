#include <iostream>

using namespace std;

class Retangulo {
    private:
        double base;
        double altura;
    public:
        Retangulo(double b = 0, double a = 0) {
            base = b;
            altura = a;
        }
        double obtemBase() {
            return base;
        }
        double obtemAltura() {
            return altura;
        }
        double area() {
            double area = base * altura;
            cout << "Area: " << area << endl;
            return area;
        }
        double perimetro() {
            double perimetro = 2 * base + 2 * altura;
            cout << "Perimetro: " << perimetro << endl;
            return perimetro;
        }
};

int main() {
    
    Retangulo ret1(6.6,7.7);
    ret1.obtemAltura();
    ret1.obtemBase();
    ret1.perimetro();
    ret1.area();
    
    return 0;
}