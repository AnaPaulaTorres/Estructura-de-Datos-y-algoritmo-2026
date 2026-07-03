void ejercicio1() {
    stack<int> pila;
    int num;
 
    cout << "Ingrese numeros (escriba -1 para terminar):\n";
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
