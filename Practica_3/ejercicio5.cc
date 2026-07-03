void ejercicio5() {
    queue<string> cola;
    string nombre;
 
    cout << "Ingrese los nombres de 10 personas:\n";
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