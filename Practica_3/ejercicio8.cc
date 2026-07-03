struct Ticket {
    int codigo;
    string cliente;
    int prioridad; // 1 = alta, 2 = media, 3 = baja
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
        }
    } while (opcion != 0);
}