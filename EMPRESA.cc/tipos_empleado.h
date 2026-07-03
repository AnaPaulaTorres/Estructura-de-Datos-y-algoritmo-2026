#ifndef TIPOS_EMPLEADO_H
#define TIPOS_EMPLEADO_H

#include "Empleado.h"

class EmpleadoHora : public Empleado {
    private:
        int horas;

    public:
        EmpleadoHora(string n, string c, int a, int h)
            : Empleado(n, c, a) {
                horas = h;
            }

            double calcularSalario() {
                if (cargo == "Gerente") return 100 * horas;
                else if (cargo == "Supervisor") return 80 * horas;
                else return 50 * horas;
            }
};

class EmpleadoPlanta : public Empleado {
    private:
        double salario;
    
    public:
        EmpleadoPlanta(string n, string c, int a, double s)
            : Empleado(n, c, a) {
                salario = s;
            }

            double calcularSalario() {
                return salario;
            }
};

#endif