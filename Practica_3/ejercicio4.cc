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
        }
    } while (opcion != 0);
}