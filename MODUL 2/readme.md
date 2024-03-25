# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Array
Array adalah kumpulan variabel yang memiliki tipe data yang sama dan dapat menyimpan beberapa nilai dalam satu variabel. Array merupakan tipe data terstruktur dalam pemrograman, yang memungkinkan untuk menyimpan data atau referensi objek dalam jumlah banyak dan terindeks. Sehingga sejumlah variabel dapat menggunakan nama yang sama [web]. Dengan menggunakan array, kita dapat menghindari penggunaan variabel yang terlalu banyak. Adapun bentuk array berdasarkan dimensinva terbagi menjadi lima, yaitu Array berdimensi satu, array berdimensi dua, array multidimensi, array empat dimensi, dan array lima dimensi.

#### 1. Array Satu Dimensi
Array satu dimensi merupakan sebuah variabel yang menyimpan sekumpulan elemen dengan tipe data homogen dan tersusun dari elemen yang sama dalam satu baris [jurnal]. Array satu dimensi memiliki banyak keuntungan karena mudah digunakan dan mudah dibaca, sehingga membuat array jenis ini menjadi yang paling umum digunakan. Elemen pertama ditandai dengan indeks 0, elemen kedua di indeks 1, dan seterusnya. Untuk mendeklarasikan sebuah array satu dimensi dalam bahasa C++, kita menggunakan tanda ```[ ]``` (bracket).

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

Dalam materi tipe data primitif, dijelaskan tentang beberapa tipe data dasar yang digunakan untuk menyimpan suatu nilai. Setiap tipe data primitif memiliki ukuran dan rentang nilai yang telah ditetapkan serta tidak dapat diubah. 

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

Fungsi dari class dan struct:
1. Membantu mengorganisir kode menjadi lebih terstruktur dan mudah dipahami.
2. Data dapat disembunyikan dan hanya dapat diakses melalui fungsi yang telah ditentukan.
3. Memungkinkan penggunaan metode yang sama dengan perilaku yang berbeda tergantung pada objek yang digunakan.
   
Berikut contoh program dari class dan struct:

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

Kode di atas merupakan contoh dari fungsi map yang digunakan untuk meyimpan pasangan data berupa key dan value. mapNamaNilai menyimpan pasangan nama dan nilai siswa. Kemudian untuk menambahkan, mengubah, dan menghapus data dari map menggunakan fungsi 'insert()', '[]', dan 'erase().

Perbedaan array dan map:
1. Array hanya dapat menyimpan data dengan tipe data yang sama, sedangkan map dapat menyimpan data dengan tipe yang berbeda.
2. Array memiliki indeks yang dimulai dari 0 dan hanya dapat diakses menggunakan indeks, sedangkan map memiliki key yang digunakan sebagai indeks dan dapat diakses menggunakan key.
3. Array memiliki ukuran yang terbatas dan tidak dapat diubah, sedangkan map memiliki ukuran yang fleksibel dan dapat diubah sesuai kebutuhan.

## Kesimpulan

Tipe data digunakan untuk mengklasifikasikan berbagai jenis data. Tiga jenis tipe data yang umum digunakan yaitu tipe data primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman, contohnya int, float, char, dan bool. Tipe data abstrak merupakan suatu tipe data buatan diri sendiri sesuai keinginan, yang dapat diimplementasikan menggunakan struct atau class. Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel, contohnya array, vector, dan map.

## Referensi
[1] M. P. Putri et al., Algoritma Dan Struktur Data. 2022.
[2] Warno, “Pembelajaran Pemrograman Bahasa Java Dan Arti Keyword,” Pembelajaran Pemrograman Bhs. Java Dan Arti Keyword, vol. 8, no. 1, pp. 40–51, 2020.
[3] D. Rosadi, “ADT (Abstract Data Type) C++,” medium.com. Accessed: Mar. 10, 2024. [Online]. Available: https://medium.com/@111202214191/adt-abstract-data-type-c-4cdcf4441d8c
[4] R. Muliono, “ABSTRACT DATA TYPE (ADT),” blog.uma.ac.id. Accessed: Mar. 10, 2024. [Online]. Available: https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
