# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided

### 1. [Soal]

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

### 2. [Soal]

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

### 3. [Soal]

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
