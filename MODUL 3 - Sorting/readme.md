# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Konsep Dasar Sorting
Pengurutan data atau sorting adalah proses menyusun kembali data yang sebelumnya telah disusun dengan suatu pola tertentu ataupun secara acak, sehingga menjadi tersusun secara teratur menurut aturan tertentu [buku]. Meskipun pengurutan ini sepertinya hanya sebuah masalah klasik dalam keinformatikaan, namun perannya tidak dapat dipisahkan terutama dalam pengolahan data. Secara umum ada 2 jenis pengurutan (sorting) data yaitu pengurutan naik (ascending), yaitu jika data disusun mulai dari nilai yang paling kecil hingga yang paling besar dan pengurutan turun (descending), yaitu jika data yang disusun mulai dari nilai yang paling besar hingga paling kecil. Algoritma pemrograman pengurutan sangat banyak dan bervariasi dari yang sederhana hingga yang kompleks. Karena materi pengurutan salah satu materi yang sangat banyak dipelajari sehingga banyak metode pengurutan yang ditemukan atau digunakan untuk melakukan pengurutan data diantaranya metode Insertion sort, Selection sort dan Bubble Sort [jurnal rita wahyuni].


#### 1. insertion Sort
Insertion sort adalah algoritma pengurutan yang bekerja dengan cara menyisipkan element baru ke dalam posisi yang tepat dalam array yang sudah terurut. Algoritma ini dimulai dari elemen kedua, dan membandingkannya dengan elemen pertama. Jika element kedua lebih kecil dari elemen pertama, maka elemen kedua disisipkan di depan elemen pertama. Proses ini diulangi untuk elemen ketiga, keempat, dan seterusnya.

Langkah-langkah algoritma insertion sort:

1. Mulai dari element kedua dalam array.
2. Bandingkan element kedua dengan element pertama.
3. Jika element kedua lebih kecil dari element pertama, maka sisipkan element kedua di depan element pertama.
4. Ulangi langkah 2 dan 3 untuk elemen-element berikutnya.

Pada langkah 2 dan 3, elemen kedua akan dibandingkan dengan elemen-elemen sebelumnya secara berurutan. Jika elemen kedua lebih kecil dari elemen sebelumnya, maka elemen kedua akan disisipkan di depan elemen tersebut.

#### 2. Selection Sort
Algoritma selection sort sering juga disebut dengan metode maksimum atau minimum. Metode maksimum karena didasarkan pada pemilihan data atau elemen maksimum sebagai dasar pengurutan. Konsepnya dengan memilih elemen maksimum kemudian mempertukarkan elemen maksimum tersebut dengan elemen paling akhir untuk urutan ascending dan elemen pertama untuk descending [jurnal endang retnoningsih]. 

Algoritma selection sort memiliki langkah-langkah sebagai berikut:

1. Pilih element terkecil dalam array dengan cara membandingkan element satu per satu (menggunakan perulangan).
2. Tukar posisi element terkecil dengan element pertama.
3. Ulangi langkah 1 dan 2 untuk elemen-elemen berikutnya.

#### 3. Bubble Sort
Metode ini merupakan metode sorting yang paling mudah, namun paling lambat dibandingkan dengan metode lainnya. Algoritma Bubble Sort merupakan proses pengurutan yang secara berangsur-angsur memindahkan data ke posisi yang tepat. Karena itulah, algoritma ini dinamakan “bubble” atau yang jika diterjemahkan ke dalam Bahasa Indonesia, artinya yaitu gelembung. Secara sederhana, bisa didefinisikan bahwa algoritma Bubble Sort adalah pengurutan dengan cara pertukaran data dengan data di sebelahnya secara terus menerus sampai pada satu iterasi tertentu dimana tidak ada lagi perubahan yang signifikan [web dosenit]. 

Langkah-langkah algoritma bubble sort:

1. Masukkan array yang akan diurutkan.
2. Lakukan perulangan sebanyak ```n-1``` kali, di mana ```n``` adalah jumlah elemen dalam array.
3. Bandingkan elemen yang ada di sebelahnya. Jika elemen sebelumnya lebih besar dari elemen berikutnya, tukar posisi keduanya.
4. Lanjutkan perulangan hingga tidak ada lagi pertukaran yang perlu dilakukan.

## Guided 

### 1. Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i=0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas mengimplementasikan operator aritmatika (+,-,*,/) pada dua angka float. Program ini menggunakan struktur kontrol 'switch' untuk mengevaluasi operator yang diberikan pengguna, kemudian menampilkan hasil operasi yang sesuai.

### 2. Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] + tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Kode di atas menggunakan struct yang digunakan untuk menyimpan beberapa variabel terkait dalam satu unit. Setelah dijalankan, program akan menampilkan informasi tentang dua mahasiswa, yang berisi nama, alamat, dan umur.



## Unguided

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

```C++
#include <iostream>
using namespace std;

void selection_sort(float arr[], int length) {
    int i, j, min;
    float temp;

    for (i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] > arr[min]) {
                min = j;
            }
        }

        // Swap the elements
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print_array(float arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    float arr[5] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "Indeks Prestasi Semester before sorting: " << endl;
    print_array(arr, length);

    selection_sort(arr, length);

    cout << "\nIndeks Prestasi Semester after sorting: " << endl;
    print_array(arr, length);
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/d5c8b1c3-93b7-4f74-85c9-1b3f1ff77d22)

Kode di atas digunakan untuk  

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void bubble_sort(string arr[], int length){
    bool not_sorted = true;
    int j=0;
    string tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i=0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

void print_array(string a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 10;
    string a[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama-nama sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nNama-nama setelah sorting: " << endl;
    print_array(a, length);
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/72c1e47f-85ee-46c8-aa1b-5a658049f510)

Kode di atas 

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/82918b9b-dd41-4c7d-bf96-236cd5c2c6b9)

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);
    for (int i = 0; i < n; ++i) {
        cout << "Masukkan karakter ke-" << i + 1 << ": ";
        cin >> characters[i];
    }

    // Urutan sebelum sorting
    cout << "Urutan karakter sebelum sorting:\n";
    for (char c : characters) {
        cout << c << " ";
    }
    cout << "\n";

    // Ascending sort
    sort(characters.begin(), characters.end());
    cout << "Urutan karakter setelah ascending sort:\n";
    for (char c : characters) {
        cout << c << " ";
    }
    cout << "\n";

    // Descending sort
    sort(characters.rbegin(), characters.rend());
    cout << "Urutan karakter setelah descending sort:\n";
    for (char c : characters) {
        cout << c << " ";
    }
    cout << "\n";

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/b00b32cb-0776-4240-9e74-4a7c36b3e0b4)

Kode di atas merupakan contoh dari fungsi map yang digunakan untuk meyimpan pasangan data berupa key dan value. mapNamaNilai menyimpan pasangan nama dan nilai siswa. Kemudian untuk menambahkan, mengubah, dan menghapus data dari map menggunakan fungsi 'insert()', '[]', dan 'erase().

## Kesimpulan

Pengurutan data atau sorting adalah proses menyusun kembali data yang sebelumnya telah disusun dengan suatu pola tertentu atau secara acak, sehingga menjadi tersusun secara teratur menurut aturan tertentu. Terdapat 2 jenis pengurutan data, yaitu pengurutan naik (ascending) dan pengurutan turun (descending). Algoritma pengurutan sangat banyak dan bervariasi dari yang sederhana hingga yang kompleks. Terdapat 3 algoritma pengurutan yang paling sering digunakan, yaitu:
1. Insertion Sort: algoritma pengurutan yang bekerja dengan cara menyisipkan elemen baru ke dalam posisi yang tepat dalam array yang sudah terurut.
2. Selection Sort: algoritma pengurutan yang didasarkan pada pemilihan data atau elemen maksimum sebagai dasar pengurutan.
3. Bubble Sort: algoritma pengurutan yang melakukan proses pengurutan secara berangsur-angsur memindahkan data ke posisi yang tepat.

## Referensi
[1] M. P. Putri et al., Algoritma Dan Struktur Data. 2022.
[2] Warno, “Pembelajaran Pemrograman Bahasa Java Dan Arti Keyword,” Pembelajaran Pemrograman Bhs. Java Dan Arti Keyword, vol. 8, no. 1, pp. 40–51, 2020.
[3] D. Rosadi, “ADT (Abstract Data Type) C++,” medium.com. Accessed: Mar. 10, 2024. [Online]. Available: https://medium.com/@111202214191/adt-abstract-data-type-c-4cdcf4441d8c
[4] R. Muliono, “ABSTRACT DATA TYPE (ADT),” blog.uma.ac.id. Accessed: Mar. 10, 2024. [Online]. Available: https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
