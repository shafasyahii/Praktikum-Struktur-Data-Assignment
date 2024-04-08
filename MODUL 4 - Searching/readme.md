# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Searching
Searching adalah tindakan mengambil data dari kumpulan data berdasarkan kunci (key) atau referensi data [buku]. Tujuan utama dari algoritma ini adalah untuk menemukan posisi atau keberadaan elemen yang dicari. Pada algoritma searching (pencarian) ada 2 metode yang digunakan yaitu : Pencarian sekuensial (Sequential search) dan pencarian biner (Binary search).

#### 1. Sequential Search
Pencarian sekuensial, juga dikenal sebagai linear search, dilakukan dengan membandingkan setiap elemen data secara berurutan dengan elemen yang dicari. Metode ini termasuk metode yang paling sederhana. Proses pencarian sequensial yaitu dengan membandingkan setiap elemen array satu per satu secara beruntun, dimulai dengan elemen pertama, sampai elemen yang dicari ditemukan atau sampai elemen terakhir dari array. Pencarian sekuensial dapat dilakukan pada elemen array yang tidak diurutkan atau pada elemen array yang diurutkan [buku]. 

Urutan	Algoritma	Sequential	Searching [jurnal ismail fauziah]:
1) I	<-0
2) Ketemu	<- false
3) Selama	(tidak	ketemu)	dan	(I	<	N)	kerjakan	baris	4
4) Jika	(Data(i)	=	key)	maka	ketemu	<- true	jika	tidak	i<-i+1
5) Jika	(ketemu)	maka	I	adalah	indeks	dari	data	yang	dicari

#### 2. Binary Search
Pencarian   Biner   (binary   Search)   adalah   metode pencarian  data  pada  array  yang  telah terurut,  metode  ini lebih  effisien  dari  pada  metode pencarian  linier  dimana semua  elemen  di  dalam  array  diuji  satu  persatu  sampai ditemukan elemen yang diinginkan [Mutiawani,  Viska,  and Irvanizam  Juwita.  "Penerapan  algoritma pencarian  biner  dalam  aplikasi  kamus  e-Acesia."  In Prosiding Seminar Nasional Informatika. 2011.]. Algoritma pencarian ini menggunakan prinsip divide and conquer, sebuah masalah atau tujuan di selesaikan dengan cara mempartisi masala menjadi bagian yang lebih kecil. Algoritma ini membagi sebuah tabel menjadi bagian yang lebih kecil atau membagi sebuah tabel menjadi dua dan memproses menjadi satu [jurnal Moh zulfitrah]. Algoritma  ini  bekerja  dengan  cara  memilih  record dengan  indeks  tengah  dari  tabel  dan  membandingkannya dengan  record  yang  hendak  dicari.  Jika  record  tersebut lebih  rendah  atau  lebih  tinggi,  maka  tabel  tersebut  dibagi dua  dan  bagian  tabel  yang  bersesuaian  akan  diproses kembali secara rekursif [jurnal rozali toyib].

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

