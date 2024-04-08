# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Tipe Data
Tipe Data digunakan untuk mengklasifikasikan berbagai jenis data. Tipe data ini wajib ada agar kompiler dapat memahami bagaimana data harus diinterpretasikan. Berikut tipe data yang akan dipelajari:
1. Tipe data primitif
2. Tipe data abstrak
3. Tipe data koleksi

#### 1. Tipe Data Primitif
Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman. Karena dasar, tipe ini tidak diturunkan dari tipe data lain [1]. Contoh tipe data primitif, antara lain:
1. Int. Diambil dari kata integer, tipe data ini digunakan untuk menyimpan bilangan bulat, seperti 1, 2, 3 dan sebagainya.
2. Float. Tipe data ini digunakan untuk menyimpan bilangan pecahan atau desimal, seperti 1.1, 2.5 dan sebagainya.
3. Char. Diambil dari kata character, tipe data ini digunakan untuk menyimpan karakter tunggal yang didefinisikan dengan diawali dan diakhiri dengan tanda petik [2].  
4. Bool. Diambil dari kata Boolean, tipe data ini digunakan untuk menyimpan dua nilai saja, yaitu true dan false.

#### 2. Tipe Data Abstrak
ADT atau Abstract Data Type merupakan suatu tipe data buatan diri sendiri sesuai keinginan. ADT dapat diimplementasikan menggunakan struktur data (struct) sebagai alternatif implementasi [3]. Dalam C++, ADT dapat dibuat dalam sebuah class yang merupakan pengembangan dari struct [4]. Data dan fungsi yang dideklarasikan private tidak dapat diakses secara langsung oleh client (class), sementara data dan fungsi yang didekralasikan public dapat diakses oleh client secara langsung (struct) [4].

#### 3. Tipe Data Koleksi
Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel. Beberapa tipe data koleksi yang umum digunakan adalah array, vector, dan map. Array adalah struktur data statis yang menyimpan elemen dengan tipe data yang sama. Sementara itu, vector adalah struktur data dinamis yang bisa menyesuaikan ukurannya saat program berjalan. Dan yang terakhir, map mirip dengan array namun dengan indeks yang memungkinkan untuk berupa tipe data selain integer. Map mengaitkan kunci dengan nilai sebagai satu pasangan.

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma sequential search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
#### Output :
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/2fbc2cf9-472b-49a6-b4db-1ea12d1d26ee)

Kode di atas mengimplementasikan 

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j;
    for(i = 0; i < length; i++) {
        min= i;
        for(j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // Tampilkan data awal
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort(data, length);

    // tampilkan data setelah diurutkan
    for(int x = 0; x < length; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    _getche();
    return EXIT_SUCCESS;
}
```
#### Output :
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/2b01ab53-2a59-422a-bd03-d69aa7367f96)

Kode di atas menggunakan 

## Unguided

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk melakukan binary search pada string
int binarySearch(const string& kalimat, char huruf) {
    int left = 0;
    int right = kalimat.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (kalimat[mid] == huruf) {
            return mid; // Huruf ditemukan pada indeks mid
        } else if (kalimat[mid] < huruf) {
            left = mid + 1; // Cari di bagian kanan
        } else {
            right = mid - 1; // Cari di bagian kiri
        }
    }

    return -1; // Huruf tidak ditemukan
}

int main() {
    string kalimat;
    char huruf;

    cout << "Masukkan kalimat atau huruf: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Ubah semua huruf menjadi lowercase untuk pencarian yang case-insensitive
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    int hasil = binarySearch(kalimat, huruf);

    if (hasil != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << hasil << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat atau huruf yang diinput." << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/29f55d58-d38c-4192-9cdb-f6df23fbd639)

Kode di atas digunakan untuk 

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence;
    int vowel_count = 0;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for (char c : sentence) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowel_count++;
        }
    }

    cout << "Number of vowels: " << vowel_count << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/5e81fa65-ff51-4ecd-9bef-849133f7a35a)

Kode di atas 

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

// Fungsi Sequential Search
int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks pertama kali ditemukan
        }
    }
    return -1; // Jika tidak ditemukan, mengembalikan -1
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int result = sequentialSearch(data, n, target);

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}\n" << endl;

    if (result != -1) {
        cout << "Angka " << target << " ditemukan pada indeks: " << result << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/ad1fa6d3-3904-4e90-a603-2a68701b4585)

Kode di atas merupakan contoh dari fungsi 

## Kesimpulan

Tipe data digunakan untuk mengklasifikasikan berbagai jenis data. Tiga jenis tipe data yang umum digunakan yaitu tipe data primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman, contohnya int, float, char, dan bool. Tipe data abstrak merupakan suatu tipe data buatan diri sendiri sesuai keinginan, yang dapat diimplementasikan menggunakan struct atau class. Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel, contohnya array, vector, dan map.

## Referensi

