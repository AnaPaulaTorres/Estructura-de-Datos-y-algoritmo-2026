#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// EJERCICIO 1: Pila de numeros -> cantidad y ultimo ingresado

void ejercicio1() {
    stack<int> pila;
    int num;

    cout << "\nIngrese numeros (escriba -1 para terminar):\n";
    cin >> num;
    while (num != -1) {
        pila.push(num);
        cin >> num;
    }

    cout << "Cantidad de elementos en la pila: " << pila.size() << endl;
    if (!pila.empty())
        cout << "Ultimo elemento ingresado: " << pila.top() << endl;
    else
        cout << "No se ingreso ningun elemento.\n";
}

// EJERCICIO 2: Invertir una palabra usando una pila

void ejercicio2() {
    string palabra;
    cout << "\nIngrese una palabra: ";
    cin >> palabra;

    stack<char> pila;
    for (char c : palabra) pila.push(c);

    string invertida = "";
    while (!pila.empty()) {
        invertida += pila.top();
        pila.pop();
    }

    cout << "Palabra invertida: " << invertida << endl;
}

// EJERCICIO 3: Verificar si una palabra es palindromo

void ejercicio3() {
    string palabra;
    cout << "\nIngrese una palabra: ";
    cin >> palabra;

    stack<char> pila;
    for (char c : palabra) pila.push(c);

    string invertida = "";
    while (!pila.empty()) {
        invertida += pila.top();
        pila.pop();
    }

    if (palabra == invertida)
        cout << palabra << " ES palindromo.\n";
    else
        cout << palabra << " NO es palindromo.\n";
}

// EJERCICIO 4: Pila de paginas visitadas (tipo navegador)

void ejercicio4() {
    stack<string> historial;
    int opcion;

    do {
        cout << "\n--- Navegador (Pila de paginas) ---\n";
        cout << "1. Visitar pagina\n";
        cout << "2. Retroceder\n";
        cout << "3. Mostrar pagina actual\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string pagina;
                cout << "Ingrese URL de la pagina: ";
                cin >> pagina;
                historial.push(pagina);
                cout << "Pagina visitada.\n";
                break;
            }
            case 2:
                if (!historial.empty()) {
                    cout << "Retrocediendo desde: " << historial.top() << endl;
                    historial.pop();
                } else {
                    cout << "No hay paginas para retroceder.\n";
                }
                break;
            case 3:
                if (!historial.empty())
                    cout << "Pagina actual: " << historial.top() << endl;
                else
                    cout << "No hay paginas visitadas.\n";
                break;
            case 0:
                cout << "Saliendo del navegador...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

// EJERCICIO 5: Cola FIFO con 10 personas

void ejercicio5() {
    queue<string> cola;
    string nombre;

    cout << "\nIngrese los nombres de 10 personas:\n";
    for (int i = 1; i <= 10; i++) {
        cout << "Persona " << i << ": ";
        cin >> nombre;
        cola.push(nombre);
    }

    cout << "\nAtendiendo en orden FIFO:\n";
    int orden = 1;
    while (!cola.empty()) {
        cout << orden++ << ". " << cola.front() << " -> atendido.\n";
        cola.pop();
    }
}

// EJERCICIO 6: Cola de clientes (con clase + cola)

class ColaClientes {
private:
    queue<string> cola;
public:
    void registrarCliente(string nombre) {
        cola.push(nombre);
        cout << nombre << " registrado en la cola.\n";
    }
    void atenderCliente() {
        if (!cola.empty()) {
            cout << "Cliente atendido: " << cola.front() << endl;
            cola.pop();
        } else {
            cout << "No hay clientes en espera.\n";
        }
    }
    void mostrarPendientes() {
        if (cola.empty()) {
            cout << "No hay clientes pendientes.\n";
        } else {
            cout << "Clientes pendientes (" << cola.size() << "):\n";
            queue<string> copia = cola;
            int i = 1;
            while (!copia.empty()) {
                cout << i++ << ". " << copia.front() << endl;
                copia.pop();
            }
        }
    }
};

void ejercicio6() {
    ColaClientes colaClientes;
    int opcion;

    do {
        cout << "\n--- Cola de clientes ---\n";
        cout << "1. Registrar cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Mostrar clientes pendientes\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                cout << "Nombre del cliente: ";
                cin >> nombre;
                colaClientes.registrarCliente(nombre);
                break;
            }
            case 2:
                colaClientes.atenderCliente();
                break;
            case 3:
                colaClientes.mostrarPendientes();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

// EJERCICIO 7: Simulacion de un banco (con clase + cola)

class Banco {
private:
    queue<string> clientes;
public:
    void agregarCliente(string nombre) {
        clientes.push(nombre);
        cout << "Cliente agregado.\n";
    }
    void atenderCliente() {
        if (!clientes.empty()) {
            cout << "Atendiendo a: " << clientes.front() << endl;
            clientes.pop();
        } else {
            cout << "No hay clientes en el banco.\n";
        }
    }
    void mostrarSiguiente() {
        if (!clientes.empty())
            cout << "Siguiente cliente: " << clientes.front() << endl;
        else
            cout << "No hay clientes en espera.\n";
    }
    void mostrarCantidad() {
        cout << "Cantidad de clientes: " << clientes.size() << endl;
    }
};

void ejercicio7() {
    Banco banco;
    int opcion;

    do {
        cout << "\n--- Simulacion de Banco ---\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Atender cliente\n";
        cout << "3. Mostrar siguiente cliente\n";
        cout << "4. Mostrar cantidad de clientes\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                cout << "Nombre del cliente: ";
                cin >> nombre;
                banco.agregarCliente(nombre);
                break;
            }
            case 2:
                banco.atenderCliente();
                break;
            case 3:
                banco.mostrarSiguiente();
                break;
            case 4:
                banco.mostrarCantidad();
                break;
            case 0:
                cout << "Saliendo del banco...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

// EJERCICIO 8: Sistema de atencion tecnica (con clase + cola)

struct Ticket {
    int codigo;
    string cliente;
    int prioridad; // 1 = alta, 2 = media, 3 = baja (solo informativo)
};

class SistemaAtencionTecnica {
private:
    queue<Ticket> tickets;
    int contador = 1;
public:
    void registrarTicket(string cliente, int prioridad) {
        Ticket t;
        t.codigo = contador++;
        t.cliente = cliente;
        t.prioridad = prioridad;
        tickets.push(t);
        cout << "Ticket #" << t.codigo << " registrado.\n";
    }
    void atenderTicket() {
        if (!tickets.empty()) {
            Ticket t = tickets.front();
            cout << "Atendiendo ticket #" << t.codigo
                 << " de " << t.cliente << endl;
            tickets.pop();
        } else {
            cout << "No hay tickets pendientes.\n";
        }
    }
    void mostrarOrden() {
        if (tickets.empty()) {
            cout << "No hay tickets en espera.\n";
        } else {
            cout << "Orden de atencion:\n";
            queue<Ticket> copia = tickets;
            int i = 1;
            while (!copia.empty()) {
                Ticket t = copia.front();
                cout << i++ << ". Ticket #" << t.codigo
                     << " - " << t.cliente
                     << " (Prioridad " << t.prioridad << ")\n";
                copia.pop();
            }
        }
    }
};

void ejercicio8() {
    SistemaAtencionTecnica sistema;
    int opcion;

    do {
        cout << "\n--- Sistema de Atencion Tecnica ---\n";
        cout << "1. Registrar ticket\n";
        cout << "2. Atender ticket\n";
        cout << "3. Mostrar orden de atencion\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string cliente;
                int prioridad;
                cout << "Nombre del cliente: ";
                cin >> cliente;
                cout << "Prioridad (1-alta, 2-media, 3-baja): ";
                cin >> prioridad;
                sistema.registrarTicket(cliente, prioridad);
                break;
            }
            case 2:
                sistema.atenderTicket();
                break;
            case 3:
                sistema.mostrarOrden();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

// EJERCICIO 9: Clase Estudiante + Lista (vector)

class Estudiante {
public:
    int codigo;
    string nombre;
    int edad;
    string carrera;

    Estudiante(int c, string n, int e, string car)
        : codigo(c), nombre(n), edad(e), carrera(car) {}

    void mostrar() {
        cout << "Codigo: " << codigo
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Carrera: " << carrera << endl;
    }
};

void ejercicio9() {
    vector<Estudiante> lista;
    int opcion;

    do {
        cout << "\n--- Gestion de Estudiantes ---\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar todos los estudiantes\n";
        cout << "3. Buscar estudiante por codigo\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int cod, edad;
                string nombre, carrera;
                cout << "Codigo: "; cin >> cod;
                cout << "Nombre: "; cin >> nombre;
                cout << "Edad: "; cin >> edad;
                cout << "Carrera: "; cin >> carrera;
                lista.push_back(Estudiante(cod, nombre, edad, carrera));
                cout << "Estudiante registrado.\n";
                break;
            }
            case 2:
                if (lista.empty()) {
                    cout << "No hay estudiantes registrados.\n";
                } else {
                    cout << "Lista de estudiantes:\n";
                    for (auto &e : lista) e.mostrar();
                }
                break;
            case 3: {
                int cod;
                cout << "Ingrese codigo a buscar: ";
                cin >> cod;
                bool encontrado = false;
                for (auto &e : lista) {
                    if (e.codigo == cod) {
                        e.mostrar();
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "Estudiante no encontrado.\n";
                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

// MENU PRINCIPAL

int main() {
    int opcion;

    do {
        cout << "\n=====================================\n";
        cout << " PRACTICA: PILAS, COLAS Y LISTAS (C++)\n";
        cout << "=====================================\n";
        cout << "1. Pila de numeros (cantidad y ultimo)\n";
        cout << "2. Invertir palabra con pila\n";
        cout << "3. Verificar palindromo con pila\n";
        cout << "4. Navegador (pila de paginas visitadas)\n";
        cout << "5. Cola FIFO de 10 personas\n";
        cout << "6. Cola de clientes\n";
        cout << "7. Simulacion de banco (cola)\n";
        cout << "8. Sistema de atencion tecnica (tickets)\n";
        cout << "9. Gestion de estudiantes (clase + lista)\n";
        cout << "0. Salir del programa\n";
        cout << "Elige un ejercicio: ";
        cin >> opcion;

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;
            case 9: ejercicio9(); break;
            case 0: cout << "Programa finalizado.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}