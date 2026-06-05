#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;

class Empleado {
    protected:
        string nombre;
        string cargo;
        int antiguedad;

    public:
        Empleado(string n, string c, int a) {
            nombre = n;
            cargo = c;
            antiguedad = a;
    }

    virtual double calcularSalario() = 0;

    string getNombre() { return nombre; }
    string getCargo() { return cargo; }
    int getAntiguedad() { return antiguedad; }

    void mostrar() {
        cout << "Nombre: " << nombre 
             << " | Cargo: " << cargo 
             << " | Antiguedad: " << antiguedad << "años" << endl;
    }
};

#endif