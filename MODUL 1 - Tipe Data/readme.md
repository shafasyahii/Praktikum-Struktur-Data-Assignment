# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Tipe Data
Tipe Data digunakan untuk mengklasifikasikan berbagai jenis data. Tipe data ini wajib ada agar kompiler dapat memahami bagaimana data harus diinterpretasikan. Berikut tipe data yang akan dipelajari:
1. Tipe data primitif
2. Tipe data abstrak
3. Tipe data koleksi

#### 1. Tipe Data Primitif
Tipe data primitive adalah tipe data dasar yang disediakan oleh banyak Bahasa pemrograman. Karena dasar, tipe ini tidak diturunkan dari tipe data lain [jurnal]. Contoh tipe data primitive, antara lain:
1. Int. Diambil dari kata integer, tipe data ini digunakan untuk menyimpan bilangan bulat, sperti 1, 2, 3 dan sebagainya.
2. Float. Tipe data ini digunakan untuk menyimpan bilangan pecahan atau decimal, seperti 1.1, 2.5 dan sebagainya.
3. Char. Diambil dari kata character, tipe data ini digunakan untuk menyimpan karakter Tunggal yang didefinisikan dengan diawali dan diakhiri dengan tanda petik [jurnal].  
4. Bool. Diambil dari kata Boolean, tipe data ini digunakan untuk menyimpan dua nilai saja, yaitu true dan false.

#### 2. Tipe Data Abstrak
ADT atau Abstract Data Type merupakan suatu tipe data buatan diri sendiri sesuai keinginan. ADT dapat diimplementasikan menggunakan struktur data (struct) sebagai alternatif implementasi [web]. Dalam C++, ADT dapat dibuat dalam sebuah class yang merupakan pengembangan dari struct [blog]. Data dan fungsi yang dideklarasikan private tidak dapat diakses secara langsung oleh client (class), sementara data dan fungsi yang didekralasikan public dapat diakses oleh client secara langsung (struct) [blog].

#### 3. Tipe Data Koleksi
Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola Kumpulan data sekaligus dalam satu variable. Beberapa tipe data koleksi yang umum digunakan adalah array, vector, dan map. Array adalah struktur data statis yang menyimpan elemen dengan tipe data yang sama. Sementara itu, vector adalah struktur data dinamis yang bisa menyesuaikan ukurannya saat program berjalan. Dan yang terakhir, map mirip dengan array namun dengan indeks yang memungkinkan untuk berupa tipe data selain integer. Map mengaitkan kunci dengan nilai sebagai satu pasangan.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// Main program
main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    
    switch(op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```
Kode di atas mengimplementasikan operator aritmatika (+,-,*,/) pada dua angka float. Program ini menggunakan struktur kontrol 'switch' untuk mengevaluasi operator yang diberikan pengguna, kemudian menampilkan hasil operasi yang sesuai.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{

    // Menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
    }
```
Kode di atas menggunakan struct yang digunakan untuk menyimpan beberapa variabel terkait dalam satu unit. Setelah dijalankan, program akan menampilkan informasi tentang dua mahasiswa, yang berisi nama, alamat, dan umur.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak isi array yang telah disisipkan. Pada program tersebut, ada sebuah array yang disisipkan dengan nilai 23, 50, 34, 78, dan 90. Setelah itu, menggunakan perintah cout, program akan menampilkan isi array yang telah disisipkan satu per satu.

## Unguided

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// int untuk bilangan bulat
int add(int a, int b) {
    return a + b;
}

// float untuk bilangan desimal
float subtract(float a, float b) {
    return a - b;
}

// Main program
int main() {
    int a = 5, b = 3;
    int result1;
    float result2;

    // Memanggil fungsi add dan menampilkan hasilnya
    result1 = add(a, b);
    cout << "Addition: " << result1 << endl;

    // Memanggil fungsi substract dan menampilkan hasilnya
    result2 = subtract(5.5, 2.5);
    cout << "Subtraction: " << result2 << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/d5c8b1c3-93b7-4f74-85c9-1b3f1ff77d22)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.
Kode di atas memiliki dua fungsi, yaitu fungsi 'add' dan 'substract'. Fungsi 'add' menerima dua parameter berupa tipe data integer dan mengembalikan nilai yang merupakan hasil penjumlahan dari kedua parameter. Sedangkan fungsi 'substract' menerima dua parameter berupa tipe data float dan mengembalikan nilai yang adalah hasil pengurangan dari kedua parameter. Pada bagian main program, kode ini akan dijalankan dan memberikan output yang sesuai dengan perintah.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
#include <iostream>
#include <string>

// struct
struct Mahasiswa {
    std::string nama;
    int semester;
};

// class
class Dosen {
public:
    std::string nama;
    std::string prodi;

    void printInfo() {
        std::cout << "Dosen Pembimbing: " << nama << ", Homebase Prodi: " << prodi << std::endl;
    }
};

// Main program
int main() {
    // Membuat object dari struct
    Mahasiswa mhs;
    mhs.nama = "Shofiari Qonita";
    mhs.semester = 9;

    // Membuat object dari class
    Dosen dosen;
    dosen.nama = "Alfiani";
    dosen.prodi = "Sains Data";

    // Menampilkan informasi
    std::cout << "Mahasiswa: " << mhs.nama << ", Semester: " << mhs.semester << std::endl;
    dosen.printInfo();

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/72c1e47f-85ee-46c8-aa1b-5a658049f510)

Kode di atas menggabungkan struct dan class, dengan struct "Mahasiswa" digunakan untuk menyimpan informasi tentang mahasiswa tersebut, seperti nama dan semester. Sedangkan class "Dosen" digunakan untuk menyimpan informasi dosen, seperti nama dan homebase prodi. Class "Dosen" juga memiliki fungsi 'printInfo' yang digunakan untuk menampilkan informasi tentang dosen. Pada bagian main program, dua object dari struct dan class tersebut dibuat dan diisi dengan informasi yang relevan, kemudian ditampilkan menggunakan perintah 'std::cout <<'.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>

// Main program
int main() {
    // Membuat map dengan tipe string sebagai key dan tipe integer sebagai value
    std::map<std::string, int> mapNamaNilai;

    // Menambahkan data ke dalam map
    mapNamaNilai.insert(std::make_pair("Susi", 25));
    mapNamaNilai.insert(std::make_pair("Budi", 30));
    mapNamaNilai.insert(std::make_pair("Agung", 35));

    // Mencetak semua data pada map
    for (const auto& item : mapNamaNilai) {
        std::cout << "Nama: " << item.first << ", Nilai: " << item.second << std::endl;
    }

    // Mengubah nilai dari key "Susi"
    mapNamaNilai["Susi"] = 26;

    // Menambahkan data baru ke dalam map
    mapNamaNilai["Dewi"] = 40;

    // Menghapus data dari key "Budi"
    mapNamaNilai.erase("Budi");

    // Mencetak semua data pada map setelah diubah
    std::cout << std::endl;
    for (const auto& item : mapNamaNilai) {
        std::cout << "Nama: " << item.first << ", Nilai: " << item.second << std::endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/b00b32cb-0776-4240-9e74-4a7c36b3e0b4)

Kode di atas merupakan contoh dari fungsi 'map' yang digunakan utnuk 

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
