#include <iostream>

using namespace std;

int main() {

    double celsius = 0;
    double fahrenheit = 0;
    double kelvin = 0;

    cout << "Digite a temperatura em Celsius:" << endl;
    cin >> celsius;
    
    fahrenheit = (celsius * 1.8) + 32;
    kelvin = celsius + 273.15;

    cout << "" << fahrenheit << " °F" << endl;
    cout << "" << kelvin << " °K" << endl;

    return 0;
}