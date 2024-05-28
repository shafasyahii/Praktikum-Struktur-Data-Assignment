# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Linked list adalah struktur data linier yang terdiri dari simpul-simpul yang saling terhubung melalui pointer. Setiap simpul menyimpan data dan alamat (pointer) ke simpul berikutnya dalam urutan. Terdapat beberapa jenis linked list, antara lain: single linked list, double linked list, circular list [1].

#### 1. Single Linked List
Single Linked List adalah sekumpulan node yang saling terhubung dengan node lain melalui sebuah pointer. Rangkaian single linked list dimulai dengan sebuah head yang menyimpan alamat awal dan diakhiri dengan node yang mengarahkan pointer ke null.

Dalam single linked list, setiap node memiliki field yang berisi pointer ke node berikutnya, serta field yang berisi data. Node terakhir menunjuk ke null, yang digunakan sebagai kondisi berhenti saat membaca isi linked list. Keuntungan dari struktur dinamis ini adalah kemampuannya untuk menambah atau mengurangi elemen dengan mudah, berbeda dengan array yang memiliki ukuran tetap.

#### 2. Double Linked List
Double Linked List (dikenal juga sebagai Doubly Linked List) adalah jenis linked list yang memiliki dua pointer. Dalam struktur ini, setiap simpul (node) memiliki dua arah penunjuk: satu menunjuk ke simpul selanjutnya (next), dan yang lainnya menunjuk ke simpul sebelumnya (prev). Berbeda dengan single linked list, doubly linked list memungkinkan kita untuk melintasinya secara dua arah.

Beberapa karakteristik dari double linked list:

1. Setiap simpul memiliki dua pointer: next dan prev.
2. Pada simpul head, pointer prev akan bernilai NULL, karena simpul head adalah simpul pertama.
3. Pada simpul tail, pointer next akan menunjuk ke NULL sebagai penanda data terakhir.

#### 3. Circular List
Circular list adalah bentuk lain dari linked list yang memberikan fleksibilitas dalam melewatkan elemen. Circular list bisa berupa single linked list atau double linked list, tetapi tidak mempunyai tail. Pada circular list, pointer next dari elemen terakhir menunjuk ke elemen pertama dan bukan menunjuk NULL. Pada double linked circular list, pointer prev dari elemen pertama menunjuk ke elemen terakhir. susunan dari single linked circular list, hanya menangani link dari elemen terakhir kembali ke elemen pertama [2].

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