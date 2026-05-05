#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx; // Controla acceso a la consola

void reloj(const string& nombre, int repeticiones, int delay_ms) {
    for(int i = 1; i <= repeticiones; i++) {
        {
            lock_guard<mutex> lock(mtx); // Bloquea mientras imprime
            cout << nombre << " - segundo " << i << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}

int main() {
    cout << "Iniciando relojes...\n" << endl;

    thread t1(reloj, "Reloj A", 5, 500);
    thread t2(reloj, "Reloj B", 5, 500);

    t1.join();
    t2.join();

    cout << "\nTodos los relojes terminaron." << endl;

    return 0;
}