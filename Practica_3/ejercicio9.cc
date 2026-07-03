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
        }
    } while (opcion != 0);
}