#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
  if (n == 0) {
    return 1; // Kasus dasar: faktorial dari 0 adalah 1
  } else {
    return n * faktorial(n - 1); // Rekursi: n! = n * (n-1)!
  }
}

int main() {
  int n;

  cout << "Masukkan bilangan bulat positif: ";
  cin >> n;

  if (n < 0) {
    cout << "Faktorial tidak terdefinisi untuk bilangan negatif." << endl;
  } else {
    cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
  }

  return 0;
}