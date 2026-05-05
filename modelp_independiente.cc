#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx; // controla la salida en consola

void tarea(int id) {
    for(int i = 1; i <= 5; i++) {
        mtx.lock();
        cout << "Hilo " << id << " ejecutando paso " << i << endl;
        mtx.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    thread h1(tarea, 1);
    thread h2(tarea, 2);
    thread h3(tarea, 3);

    h1.join();
    h2.join();
    h3.join();

    return 0;
}