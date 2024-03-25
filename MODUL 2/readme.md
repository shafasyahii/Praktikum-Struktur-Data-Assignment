# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Array
Array adalah kumpulan variabel yang memiliki tipe data yang sama dan dapat menyimpan beberapa nilai dalam satu variabel. Array merupakan tipe data terstruktur dalam pemrograman, yang memungkinkan untuk menyimpan data atau referensi objek dalam jumlah banyak dan terindeks. Sehingga sejumlah variabel dapat menggunakan nama yang sama [web]. Dengan menggunakan array, kita dapat menghindari penggunaan variabel yang terlalu banyak. Adapun bentuk array berdasarkan dimensinva terbagi menjadi lima, yaitu Array berdimensi satu, array berdimensi dua, array multidimensi, array empat dimensi, dan array lima dimensi.

#### 1. Array Satu Dimensi
Array satu dimensi merupakan sebuah variabel yang menyimpan sekumpulan elemen dengan tipe data homogen dan hanya memiliki satu indeks [jurnal logika]. Elemen pertama ditandai dengan indeks 0, elemen kedua di indeks 1, dan seterusnya. Array satu dimensi ini mudah digunakan dan mudah dibaca sehingga membuat array jenis ini menjadi yang paling umum digunakan. Untuk mendeklarasikan sebuah array satu dimensi kita menggunakan tanda ```[ ]``` (bracket). Bentuk umum pendeklarasian array satu dimensi adalah sebagai berikut: 
!```tipe_data nama_array[jumlah_elemen];```
Contoh:
!```int Nilai[10];```
Kita dapat memberikan nilai pada elemen array saat pendeklarasian. Misalnya:
!```int Nilai[10] = {1, 2, 4, 5, 3,7, 6, 9, 8, 10};```
Dalam contoh ini, kita telah memesan tempat pada memori komputer sebanyak 10 tempat (indeks 0 hingga 9) dan mengisinya dengan nilai-nilai yang diberikan.

#### 2. Array Dua Dimensi


## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Kode di atas mengimplementasikan operator aritmatika (+,-,*,/) pada dua angka float. Program ini menggunakan struktur kontrol 'switch' untuk mengevaluasi operator yang diberikan pengguna, kemudian menampilkan hasil operasi yang sesuai.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
kode 

## Unguided

### 1.  Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/54d9ddfd-cd8e-4828-925d-e1d82e3185ef)

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
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/6a9b349d-7c92-4e1e-9530-3d864b0bdee0)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.
Kode di atas memiliki dua fungsi, yaitu fungsi 'add' dan 'substract'. Fungsi 'add' menerima dua parameter berupa tipe data integer dan mengembalikan nilai yang merupakan hasil penjumlahan dari kedua parameter. Sedangkan fungsi 'substract' menerima dua parameter berupa tipe data float dan mengembalikan nilai yang adalah hasil pengurangan dari kedua parameter. Pada bagian main program, kode ini akan dijalankan dan memberikan output yang sesuai dengan perintah.

Dalam materi tipe data primitif, dijelaskan tentang beberapa tipe data dasar yang digunakan untuk menyimpan suatu nilai. Setiap tipe data primitif memiliki ukuran dan rentang nilai yang telah ditetapkan serta tidak dapat diubah. 

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

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

## Kesimpulan

Tipe data digunakan untuk mengklasifikasikan berbagai jenis data. Tiga jenis tipe data yang umum digunakan yaitu tipe data primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman, contohnya int, float, char, dan bool. Tipe data abstrak merupakan suatu tipe data buatan diri sendiri sesuai keinginan, yang dapat diimplementasikan menggunakan struct atau class. Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel, contohnya array, vector, dan map.

## Referensi
[1] M. P. Putri et al., Algoritma Dan Struktur Data. 2022.
[2] Warno, “Pembelajaran Pemrograman Bahasa Java Dan Arti Keyword,” Pembelajaran Pemrograman Bhs. Java Dan Arti Keyword, vol. 8, no. 1, pp. 40–51, 2020.
[3] D. Rosadi, “ADT (Abstract Data Type) C++,” medium.com. Accessed: Mar. 10, 2024. [Online]. Available: https://medium.com/@111202214191/adt-abstract-data-type-c-4cdcf4441d8c
[4] R. Muliono, “ABSTRACT DATA TYPE (ADT),” blog.uma.ac.id. Accessed: Mar. 10, 2024. [Online]. Available: https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
