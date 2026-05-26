#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> lista = {1, 2, 3, 4, 5, 6, 7};
    reverse(lista.begin(), lista.end());

    cout << "Lista invertida: ";
    for (int n : lista) cout << n << " ";
    return 0;
}
