#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Tipos_Empleado.h"

using namespace std;

int main() {
    
    vector<Empleado*> empleados;

    empleados.push_back(new EmpleadoPlanta("Ana","Gerente",10,5000));
    empleados.push_back(new EmpleadoHora("Luis","Supervisor",3,40));
    empleados.push_back(new EmpleadoHora("Alice","Operario",2,40));
    empleados.push_back(new EmpleadoPlanta("Paula","Gerente",6,40));
    empleados.push_back(new EmpleadoPlanta("Jose","Supervisor",8,4000));
    empleados.push_back(new EmpleadoPlanta("Lucia","Operario",4,3000));
    empleados.push_back(new EmpleadoHora("Pedro","Operario",1,40));
    empleados.push_back(new EmpleadoHora("Elena","Supervisor",6,40));
    empleados.push_back(new EmpleadoPlanta("Miguel","Gerente",12,550));
    empleados.push_back(new EmpleadoHora("Sofia","Operario",2,40));

    cout << "\n--- SALARIOS ---\n";
    for (auto e : empleados) {
        e->mostrar();
        cout << "Salario: $" << e->calcularSalario() << endl;
    }

    Empleado* mayor = empleados[0];
    for (auto e : empleados) {
        if (e->calcularSalario() > mayor->calcularSalario()) {
            mayor = e;
        }
    }

    cout << "\n--- MAYOR SALARIO ---\n";
    mayor->mostrar();
    cout << "Salario: $" << mayor->calcularSalario() << endl;

    int maxAnt = 0;
    for (auto e : empleados) {
        if (e->getAntiguedad() > maxAnt) {
            maxAnt = e->getAntiguedad();
        }
    }

    cout << "\n--- MAYOR ANTIGUEDAD ---\n";
    for (auto e : empleados) {
        if (e->getAntiguedad() == maxAnt) {
            e->mostrar();
        }
    }

    sort(empleados.begin(), empleados.end(),
        [](Empleado* a, Empleado* b) {
            return a->getCargo() < b->getCargo();
        });
    
    cout << "\n--- ORDENADOS POR CARGO ---\n";
    for (auto e : empleados) {
        e->mostrar();
    }

    ofstream archivo("empleados.txt");
    if (archivo.is_open()) {
        for (auto e : empleados) {
            archivo << "Nombre: " << e->getNombre() << endl;
            archivo << "Cargo: " << e->getCargo() << endl;
            archivo << "Antiguedad: " << e->getAntiguedad() << endl;
            archivo << "Salario: " << e->calcularSalario() << endl;
            archivo << "------------------------" << endl;
        }
        archivo.close();
        cout << "\nDatos guardados en empleados.txt\n";
    } else {
        cout << "Error al abrir el archivo\n";
    }

    return 0;
} 