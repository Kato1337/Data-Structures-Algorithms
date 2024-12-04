#include <iostream>
using namespace std;


int main() {
    double temperature;
    int choice;

    cout << "Enter Temperature: ";
    cin >> temperature;

    cout << "1. Fahrenheit to Celcius\n";
    cout << "2. Celcius to Fahrenheit\n";
    cout << "Choose an option:  ";
    cin >> choice;

    if (choice == 1) {
        double Celcius = (temperature - 32) * 5.0 / 9.0;
        cout << "Temperature to Celcius: " << Celcius;
    }
    else if (choice == 2) {
        double Fahrenheit = (temperature * 9.0 / 5.0) + 32;
        cout << "Temperature to Fahrenheit: " << Fahrenheit;
    }
    
    return 0;
}