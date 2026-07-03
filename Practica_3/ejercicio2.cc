void ejercicio2() {
    string palabra;
    cout << "Ingrese una palabra: ";
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