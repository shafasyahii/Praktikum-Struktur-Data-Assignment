# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori


#### 1. 

## Guided 

### 1. Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n-1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```
Kode di atas digunakan untuk 

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n-1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
Kode di atas digunakan untuk

## Unguided

### 1.	Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
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
```
#### Output:
![Screenshot 2024-04-29 141735](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/a2b79113-15bc-458f-b1e9-0a50aafe7ccd)

Kode di atas digunakan untuk 

### 2.	Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
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
```
#### Output:
![Screenshot 2024-04-29 141735](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/a2b79113-15bc-458f-b1e9-0a50aafe7ccd)

Kode di atas digunakan untuk

## Kesimpulan

Linked List adalah struktur data linier yang terdiri dari simpul-simpul yang saling terhubung melalui pointer, dengan Single Linked List sebagai jenis paling sederhana yang memiliki pointer ke node berikutnya dan field untuk data, Double Linked List yang memiliki dua pointer untuk melintasi secara dua arah, dan Circular List yang memberikan fleksibilitas dalam melewatkan elemen dengan pointer next dari elemen terakhir menunjuk ke elemen pertama.

## Referensi
[1] M. Erkamim et al., Buku Ajar Algoritma Dan Struktur Data, no. January. 2024.

[2] A. Sindar, Struktur Data Dan Algoritma, no. December. 2018.