#include <iostream>
#include <sstream>

using namespace std;

class ponto {
    private:
        double x;
        double y;
    public:
        ponto(double px = 0.0, double py = 0.0) {
            x = px;
            y = py;
        }
        double obtemX() const {
            return x;
        }

        double obtemY() const {
            return y;
        }

        void defineX(double px) {
            x = px;
        }

        void defineY(double py) {
            x = py;
        }

        string str () const {
            stringstream ss;
            ss << "(" << x << "," << y << ")";
            return ss.str();
        }

        ponto operator+(ponto &p) {
            return ponto( x + p.x , y + p.y );
        }

        ponto operator+(double d) {
            return
        }
};