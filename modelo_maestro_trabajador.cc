#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

vector<int> tareas = {1, 2, 3, 4, 5, 6, 7, 8};

vector<int> resultados;

mutex mtx;

void trabajador(int id, int inicio, int fin) {

    for (int i = inicio; i < fin; i++) {

        int resultado = tareas[i] * tareas[i];

        mtx.lock();
        resultados.push_back(resultado);
        cout << "[Trabajador " << id << "] procesa: " 
             << tareas[i] << " -> " << resultado << endl;
        mtx.unlock();
    }
}

int main() {

    int n = tareas.size();

    int mitad = n / 2;

    thread t1(trabajador, 1, 0, mitad);
    thread t2(trabajador, 2, mitad, n);

    t1.join();
    t2.join();

    cout << "\nResultados finales: ";
    for (int x : resultados) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}