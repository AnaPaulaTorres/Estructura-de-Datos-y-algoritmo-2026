#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

queue<int> buffer;
const unsigned int MAX_BUFFER = 5;

mutex mtx;
condition_variable cv;

// PRODUCTOR
void productor() {
    int valor = 1;

    while (valor <= 10) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return buffer.size() < MAX_BUFFER;
        });

        buffer.push(valor);
        cout << "[Productor] produce: " << valor << endl;

        valor++;

        lock.unlock();
        cv.notify_all();
    }
}

// CONSUMIDOR
void consumidor() {

    int consumidos = 0;

    while (consumidos < 10) {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [] {
            return !buffer.empty();
        });

        int valor = buffer.front();
        buffer.pop();

        cout << "[Consumidor] consume: " << valor << endl;

        consumidos++;

        lock.unlock();
        cv.notify_all();
    }
}

int main() {

    thread t1(productor);
    thread t2(consumidor);

    t1.join();
    t2.join();

    cout << "\nProceso terminado (Productor-Consumidor)" << endl;

    return 0;
}