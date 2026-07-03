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
        }
    } while (opcion != 0);
}