# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Searching
Searching adalah tindakan mengambil data dari kumpulan data berdasarkan kunci (key) atau referensi data [1]. Tujuan utama dari algoritma ini adalah untuk menemukan posisi atau keberadaan elemen yang dicari. Pada algoritma searching (pencarian) ada 2 metode yang digunakan yaitu : Pencarian sekuensial (Sequential search) dan pencarian biner (Binary search).

#### 1. Sequential Search
Pencarian sekuensial, juga dikenal sebagai linear search, dilakukan dengan membandingkan setiap elemen data secara berurutan dengan elemen yang dicari. Metode ini termasuk metode yang paling sederhana. Proses pencarian sequensial yaitu dengan membandingkan setiap elemen array satu per satu secara beruntun, dimulai dengan elemen pertama, sampai elemen yang dicari ditemukan atau sampai elemen terakhir dari array. Pencarian sekuensial dapat dilakukan pada elemen array yang tidak diurutkan atau pada elemen array yang diurutkan [1]. 

Urutan	Algoritma	Sequential	Searching [2]:
1) I	<-0
2) Ketemu	<- false
3) Selama	(tidak	ketemu)	dan	(I	<	N)	kerjakan	baris	4
4) Jika	(Data(i)	=	key)	maka	ketemu	<- true	jika	tidak	i<-i+1
5) Jika	(ketemu)	maka	I	adalah	indeks	dari	data	yang	dicari

#### 2. Binary Search
Pencarian   Biner   (binary   Search)   adalah   metode pencarian  data  pada  array  yang  telah terurut,  metode  ini lebih  effisien  dari  pada  metode pencarian  linier  dimana semua  elemen  di  dalam  array  diuji  satu  persatu  sampai ditemukan elemen yang diinginkan [3]. Algoritma pencarian ini menggunakan prinsip divide and conquer, sebuah masalah atau tujuan di selesaikan dengan cara mempartisi masala menjadi bagian yang lebih kecil. Algoritma ini membagi sebuah tabel menjadi bagian yang lebih kecil atau membagi sebuah tabel menjadi dua dan memproses menjadi satu [4]. Algoritma  ini  bekerja  dengan  cara  memilih  record dengan  indeks  tengah  dari  tabel  dan  membandingkannya dengan  record  yang  hendak  dicari.  Jika  record  tersebut lebih  rendah  atau  lebih  tinggi,  maka  tabel  tersebut  dibagi dua  dan  bagian  tabel  yang  bersesuaian  akan  diproses kembali secara rekursif [5].

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

Kode di atas merupakan implementasi algoritma pencarian sekuensial (sequential search). Algoritma ini digunakan untuk mencari elemen tertentu dalam sebuah array dengan cara memeriksa setiap elemen satu per satu hingga ditemukan elemen yang dicari atau sampai seluruh array telah diperiksa. Pertama kita inisialisasi data dengan memasukkan array ```data``` berisi 10 angka, yaitu {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}. Kemudian membuat variabel ```cari```, angka yang ingin dicari adalah 10. Melalui loop ```for```, program memeriksa setiap elemen array ```data```. Jika ditemukan angka yang sama dengan ```cari```, variabel ```ketemu``` diubah menjadi ```true``` dan indeks elemen tersebut disimpan dalam variabel ```i```. Hasil dari program ini akan menunjukkan apakah angka 10 ada dalam array ```data``` dan jika iya, pada indeks ke berapa. Angka 10 ditemukan pada indeks ke-9 (indeks dimulai dari 0).

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

Kode di atas adalah implementasi dari algoritma Binary Search. Program ini bertujuan untuk mencari suatu data tertentu dalam sebuah array menggunakan metode Binary Search. Data yang ingin dicari dimasukkan oleh pengguna melalui input. Pertama, program menampilkan data awal yang terdapat pada array. Kemudian, data diurutkan menggunakan algoritma Selection Sort agar dapat melakukan pencarian dengan efisien. Setelah data diurutkan, program meminta pengguna memasukkan data yang ingin dicari. Algoritma Binary Search digunakan untuk mencari data yang ingin dicari tadi pada array yang sudah ditentukan diawal. Jika data ditemukan, program menampilkan index tempat data tersebut berada. Jika tidak ditemukan, program memberikan pesan bahwa data tidak ditemukan.

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

Kode di atas digunakan untuk melakukan binary search pada string. Fungsi ```binarySearch``` menerima dua parameter yaitu ```kalimat``` yang berisi sebuah string dan ```huruf``` yang berisi sebuah karakter. Fungsi ini menggunakan algoritma binary search untuk mencari posisi karakter ```huruf``` dalam string ```kalimat```. Jika karakter ```huruf``` ditemukan, fungsi akan mengembalikan indeksnya. Jika karakter ```huruf``` tidak ditemukan, fungsi akan mengembalikan -1. Selama belum menemukan karakter yang dicarit, fungsi ini akan melakukan iterasi sampai batas kiri lebih besar dari batas kanan. Pada setiap iterasi, fungsi akan membagi data menjadi dua bagian dan memilih bagian tengah untuk dibandingkan dengan karakter yang ingin dicari. Jika karakter yang dicari lebih besar dari karakter pada indeks tengah, maka fungsi akan melakukan pencarian pada bagian kanan. Sebaliknya, jika karakter yang dicari lebih kecil dari karakter pada indeks tengah, maka fungsi akan melakukan pencarian pada bagian kiri. Proses ini akan terus dilakukan sampai karakter dicari ditemukan atau bagian data habis.

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

    cout << "Jumlah huruf vokal: " << vowel_count << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/06ac61d8-cc37-4aab-9582-a7179b7de33e)

Kode di atas bertujuan untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna. Pertama, program meminta pengguna untuk memasukkan sebuah kalimat sesuai yang diinginkan. Setelah menerima input kalimat, program akan mengiterasi melalui setiap karakter dalam kalimat tersebut. Jika karakter adalah huruf vokal (baik huruf kecil maupun huruf besar), maka variabel ```vowel_count``` akan bertambah satu. Setelah selesai menghitung, program akan menampilkan jumlah huruf vokal yang ada dalam kalimat yang telah diinput pengguna.

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

Kode di atas merupakan implemetasi dari algoritma pencarian secara urut (Sequential Search) untuk mencari angka yang diinginkan dalam array. Jika angka yang diinginkan ditemukan, fungsi akan mengembalikan indeks pertama kali ditemukan. Jika tidak ditemukan, fungsi akan mengembalikan -1. Dalam program ini, array ```data``` berisi angka-angka yang akan dicari. Variabel ```n``` berisi jumlah elemen dalam array. Variabel ```target``` berisi angka yang akan dicari. Program menggunakan fungsi ```sequentialSearch``` untuk mencari angka ```target``` dalam array ```data```. Fungsi ini menggunakan perulangan untuk melakukan pencarian. Hasil pencarian akan ditampilkan melalui output. Jika angka target ditemukan, output akan menampilkan indeks pertama kali ditemukan. Jika tidak ditemukan, output akan menampilkan pesan "Angka [target] tidak ditemukan dalam data."

## Kesimpulan

Searching adalah tindakan mengambil data dari kumpulan data berdasarkan kunci (key) atau referensi data. Tujuan utama dari algoritma ini adalah untuk menemukan posisi atau keberadaan elemen yang dicari. Ada dua metode pencarian yang digunakan, yaitu pencarian sekuensial (Sequential search) dan pencarian biner (Binary search).

Sequential search dilakukan dengan membandingkan setiap elemen data secara berurutan dengan elemen yang dicari, dimulai dari elemen pertama hingga elemen terakhir. Metode ini termasuk metode yang paling sederhana. Pencarian sekuensial dapat dilakukan pada elemen array yang tidak diurutkan atau pada elemen array yang diurutkan. Pencarian Biner (binary Search) adalah metode pencarian data pada array yang telah terurut, lebih effisien dari pencarian linier. Algoritma pencarian ini menggunakan prinsip divide and conquer. Algoritma ini bekerja dengan cara memilih record dengan indeks tengah dari tabel dan membandingkannya dengan record yang hendak dicari. Jika record tersebut lebih rendah atau lebih tinggi, maka tabel tersebut dibagi dua dan bagian tabel yang bersesuaian akan diproses kembali secara rekursif.

## Referensi
[1] M. T. Putra, Munawir, and A. R. Yuniarti, Belajar Pemrograman Lanjut Dengan C++. 2023.

[2] Ismail, Fauziah, and Hayati Nur, “Algoritma Sequential Search Dan Binary Search Pada Sistem Pencarian E-Arsip Berbasis Web,” Kumpul. J. Ilmu Komput., vol. 09, pp. 1–11, 2022.

[3] Mutiawani,  Viska,  and Irvanizam  Juwita.  "Penerapan  algoritma pencarian  biner  dalam  aplikasi  kamus  e-Acesia."  In Prosiding Seminar Nasional Informatika. 2011.

[4] M. Z. Fitrah, R. Satra, and L. Budi Ilmawan, “Penerapan Algoritma Binary Search Pada Aplikasi Kamus Bahasa Wolio (Buton),” Bul. Sist. Inf. dan Teknol. Islam, vol. 2, no. 4, pp. 265–274, 2021, doi: 10.33096/busiti.v2i4.998.

[5] R. Toyib, Y. Darnita, and A. R. S. Deva, “Penerapan Algoritma Binary Search Pada Aplikasi E-Order,” J. Media Infotama, vol. 17, no. 1, pp. 30–37, 2021, doi: 10.37676/jmi.v17i1.1314.
