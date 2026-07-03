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
        }
    } while (opcion != 0);
}