int main() {
    int opcion;
 
    do {
        cout << "\n=====================================\n";
        cout << " PRACTICA: PILAS, COLAS Y LISTAS (C++)\n";
        cout << "=====================================\n";
        cout << "1. Pila de numeros (cantidad y ultimo)\n";
        cout << "2. Invertir palabra con pila\n";
        cout << "3. Verificar palindromo con pila\n";
        cout << "4. Navegador (pila de paginas visitadas)\n";
        cout << "5. Cola FIFO de 10 personas\n";
        cout << "6. Cola de clientes\n";
        cout << "7. Simulacion de banco (cola)\n";
        cout << "8. Sistema de atencion tecnica (tickets)\n";
        cout << "9. Gestion de estudiantes (clase + lista)\n";
        cout << "10. Agenda de contactos (clase + lista)\n";
        cout << "0. Salir del programa\n";
        cout << "Elige un ejercicio: ";
        cin >> opcion;
 
        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: ejercicio5(); break;
            case 6: ejercicio6(); break;
            case 7: ejercicio7(); break;
            case 8: ejercicio8(); break;
            case 9: ejercicio9(); break;
            case 10: ejercicio10(); break;
            case 0: cout << "Programa finalizado.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
 
    return 0;
}