void ejercicio3() {
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
 
    if (palabra == invertida)
        cout << palabra << " ES palindromo.\n";
    else
        cout << palabra << " NO es palindromo.\n";
}