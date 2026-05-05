#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int arr[] = {1,2,3,4,5,6,7,8};
int n = 8;

int suma1 = 0;
int suma2 = 0;

mutex mtx;

void sumarPrimeraMitad() {
    for (int i = 0; i < n/2; i++) {
        suma1 += arr[i];

        mtx.lock();
        cout << "[Hilo 1] sumando " << arr[i] << endl;
        mtx.unlock();
    }
}

void sumarSegundaMitad() {
    for (int i = n/2; i < n; i++) {
        suma2 += arr[i];

        mtx.lock();
        cout << "[Hilo 2] sumando " << arr[i] << endl;
        mtx.unlock();
    }
}

int main() {

    thread t1(sumarPrimeraMitad);
    thread t2(sumarSegundaMitad);

    t1.join();
    t2.join();

    cout << "\nSuma total (modelo paralelo): " << suma1 + suma2 << endl;

    return 0;
}