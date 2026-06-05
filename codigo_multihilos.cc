#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx; 

void descargarArchivo(string nombre, int tiempo) {
    for (int i = 1; i <= 100; i += 20) {
        
        this_thread::sleep_for(chrono::milliseconds(tiempo));

        mtx.lock(); // Bloquea acceso
        cout << nombre << " descargando: " << i << "%" << endl;
        mtx.unlock(); // Libera acceso
    }

    mtx.lock();
    cout << nombre << " DESCARGA COMPLETADA " << endl;
    mtx.unlock();
}

int main() {

    // Crear hilos (descargas simultáneas)
    thread t1(descargarArchivo, "Archivo 1", 500);
    thread t2(descargarArchivo, "Archivo 2", 700);
    thread t3(descargarArchivo, "Archivo 3", 600);

    t1.join();
    t2.join();
    t3.join();

    cout << "\nTodas las descargas finalizaron " << endl;

    return 0;
}