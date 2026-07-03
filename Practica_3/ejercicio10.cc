class Contacto {
public:
    string nombre;
    string telefono;
    string correo;
 
    Contacto(string n, string t, string c)
        : nombre(n), telefono(t), correo(c) {}
 
    void mostrar() {
        cout << "Nombre: " << nombre
             << " | Telefono: " << telefono
             << " | Correo: " << correo << endl;
    }
};
 
void ejercicio10() {
    vector<Contacto> contactos;
    int opcion;
 
    do {
        cout << "\n--- Agenda de Contactos ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar por nombre\n";
        cout << "3. Eliminar contacto\n";
        cout << "4. Mostrar todos los contactos\n";
        cout << "5. Mostrar ordenados alfabeticamente (PLUS)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
 
        switch (opcion) {
            case 1: {
                string nombre, telefono, correo;
                cout << "Nombre: "; cin >> nombre;
                cout << "Telefono: "; cin >> telefono;
                cout << "Correo: "; cin >> correo;
                contactos.push_back(Contacto(nombre, telefono, correo));
                cout << "Contacto agregado.\n";
                break;
            }
            case 2: {
                string nombre;
                cout << "Nombre a buscar: ";
                cin >> nombre;
                bool encontrado = false;
                for (auto &c : contactos) {
                    if (c.nombre == nombre) {
                        c.mostrar();
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "Contacto no encontrado.\n";
                break;
            }
            case 3: {
                string nombre;
                cout << "Nombre a eliminar: ";
                cin >> nombre;
                bool eliminado = false;
                for (size_t i = 0; i < contactos.size(); i++) {
                    if (contactos[i].nombre == nombre) {
                        contactos.erase(contactos.begin() + i);
                        eliminado = true;
                        cout << "Contacto eliminado.\n";
                        break;
                    }
                }
                if (!eliminado) cout << "Contacto no encontrado.\n";
                break;
            }
            case 4:
                if (contactos.empty()) cout << "No hay contactos registrados.\n";
                else for (auto &c : contactos) c.mostrar();
                break;
            case 5: {
                // PLUS: ordenar alfabeticamente por nombre usando sort()
                vector<Contacto> ordenados = contactos;
                sort(ordenados.begin(), ordenados.end(),
                     [](Contacto &a, Contacto &b) { return a.nombre < b.nombre; });
                for (auto &c : ordenados) c.mostrar();
                break;
            }
        }
    } while (opcion != 0);
}