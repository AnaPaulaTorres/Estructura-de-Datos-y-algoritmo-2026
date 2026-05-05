#include <iostream>
using namespace std;

int main() {

    int arr[] = {2, 5, 8, 10, 3, 6, 7, 4};
    int n = 8;

    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            contador++;
            cout << arr[i] << " es par" << endl;
        }
    }

    cout << "\nTotal de pares (secuencial): " << contador << endl;

    return 0;
}