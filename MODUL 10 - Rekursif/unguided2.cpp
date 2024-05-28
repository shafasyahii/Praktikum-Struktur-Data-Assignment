#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial (fungsi pembantu)
int faktorialHelper(int n, int acc) {
    if (n == 0) {
        return acc; // mengembalikan nilai akumulasi
    } else {
        return faktorialHelper(n - 1, acc * n); // Rekursi: mengalikan n dengan akumulasi dan melanjutkan rekursi
    }
}

int main() {
    int n;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Faktorial tidak terdefinisi untuk bilangan negatif." << endl;
    } else {
        cout << "Faktorial dari " << n << " adalah: " << faktorialHelper(n, 1) << endl; // Memanggil fungsi pembantu dengan nilai awal akumulasi 1
    }

    return 0;
}