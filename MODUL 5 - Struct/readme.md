# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Struct
Struktur adalah koleksi dari variabel yang dinyatakan dengan sebuah nama, dengan sifat setiap variabel dapat memiliki tipe yang berlainan. Struktur biasa dipakai untuk mengelompokkan beberapa informasi yang berkaitan menjadi sebuah satu kesatuan[1]. Biasanya penamaan antar variabel di dalam struct saling berkaitan dan mendukung satu gagasan. Di dalam sebuah struct dapat dimungkinkan terdapat sebuah struct lagi. Hal ini dapat diartikan struct di dalam struct. Hampir sama dengan nested loop, yaitu for di dalam for. Struktur mempunyai persamaan dengan array yaitu pengalokasian memori untuk elemen-elemennya sudah di tentukan sebelum program dijalankan. Sedangkan perbedaannya, array memiliki tipe data dari elemen-elennya harus sama dan elemen-elemennya diaksesmenggunakan indeks dan struct memiliki tipe data dari elemen-elennya tidak harus sama dan elemen-elemennya diakses menggunakan identifier atau nama variabel.

#### Cara membuat struct
Struct dapat dibuat dengan kata kunci struct kemudian diikuti dengan nama struct dan isinya.
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/e2dc8ae6-7fdd-40a4-909c-691143199c93)

contoh :
```C++
struct Mahasiswa
{
    char *name;
    char *address;
    int age;
};
```

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```
Kode di atas digunakan untuk menampilkan informasi tentang buku favorit pengguna. Pengguna mendefinisikan struktur buku dengan anggota judul, pengarang, penerbit, tebal halaman, dan harga menggunakan fungsi ```struct```. Kemudian variabel ```favorit``` dibuat dengan tipe buku dan diisi dengan informasi buku favorit yang telah dibuat pada struktur tadi. Program kemudian menampilkan informasi tersebut ke konsol menggunakan fungsi ```cout```.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/08a9387a-68c1-4021-a735-26a7ac89b314)


```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
Kode di atas mendefinisikan struktur data untuk hewan dan menampilkan informasi tentang mereka. Struktur data dibagi menjadi tiga jenis: hewan secara umum, hewan darat, dan hewan laut yang dibuat menggunakan fungsi ```struct```. Masing-masing struktur memiliki ciri yang sesuai, seperti nama, jenis kelamin, cara berkembang biak, alat pernapasan, tempat hidup, dan karakteristik khusus (misalnya, jumlah kaki untuk hewan darat atau bentuk sirip untuk hewan laut). Kode selanjutnya mendeklarasikan tiga variabel kelinci, ikan, dan serigala menggunakan structs yang telah didefinisikan sebelumnya. Kode kemudian menginisialisasi variabel dengan nilai tertentu. Terakhir, kode menampilkan data setiap hewan menggunakan fungsi ```cout```.

## Unguided

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
#include <iostream>
#include <string>

using namespace std;

// Create a structure named 'buku' with arrays of size 5
struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

int main() {
    // Initialize and fill the 'buku' structure
    buku favorit;
    favorit.judul_buku[0] = "The Catcher in the Rye";
    favorit.judul_buku[1] = "Catch-22";
    favorit.judul_buku[2] = "To Kill a Mockingbird";
    favorit.judul_buku[3] = "1984";
    favorit.judul_buku[4] = "Brave New World";

    favorit.pengarang[0] = "J.D. Salinger";
    favorit.pengarang[1] = "Joseph Heller";
    favorit.pengarang[2] = "Harper Lee";
    favorit.pengarang[3] = "George Orwell";
    favorit.pengarang[4] = "Aldous Huxley";

    favorit.penerbit[0] = "Little, Brown and Company";
    favorit.penerbit[1] = "Simon & Schuster";
    favorit.penerbit[2] = "Harper & Row";
    favorit.penerbit[3] = "Secker and Warburg";
    favorit.penerbit[4] = "Chatto & Windus";

    favorit.tebal_halaman[0] = 277;
    favorit.tebal_halaman[1] = 453;
    favorit.tebal_halaman[2] = 281;
    favorit.tebal_halaman[3] = 328;
    favorit.tebal_halaman[4] = 199;

    favorit.harga_buku[0] = 9.99;
    favorit.harga_buku[1] = 12.99;
    favorit.harga_buku[2] = 7.99;
    favorit.harga_buku[3] = 10.99;
    favorit.harga_buku[4] = 8.99;

    // Display the content of the 'buku' structure
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku Favorit Saya" << endl;
        cout << "\tJudul Buku : " << favorit.judul_buku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.harga_buku[i] << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/7724986d-8afc-41c0-9e6a-64b64ce1ac14)

Kode di atas digunakan untuk menyimpan dan mengeluarkan informasi tentang lima buku favorit. Program ini menggunakan struktur data bernama ```buku``` untuk menyimpan data-data tersebut. Struktur buku terdiri dari lima array, yaitu ```judul_buku```, ```pengarang```, ```penerbit```, ```tebal_halaman```, dan ```harga_buku```, yang berukuran masing-masing 5. Array-array ini akan digunakan untuk menyimpan judul, nama pengarang, nama penerbit, tebal halaman, dan harga buku-buku favorit. Dalam fungsi ```main()```, variabel favorit dideklarasikan sebagai instance dari struktur buku. Kemudian, data-data buku favorit diinisialisasi dan disimpan ke dalam array-array tersebut. Setelah itu, data-data tersebut dicetak menggunakan perulangan ```for``` dan fungsi ```cout```.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

Mengubah struktur data dari struct ke array akan menghasilkan kode yang berbeda dengan beberapa perubahan fungsional.

#### Perbedaan Utama:
- Tipe data: ```struct``` mendefinisikan tipe data baru, ```array``` adalah koleksi elemen.
- Organisasi data: ```struct``` terstruktur, ```array``` berurutan.
- Penggunaan memori: ```struct``` menggunakan memori lebih efisien untuk data terkait erat, ```array``` membutuhkan lebih banyak memori.

Jika kita ubah ```struct``` buku menjadi ```array```, kodenya akan menjadi seperti berikut:

```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Deklarasi array
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];

    // Mengisi data
    judul_buku[0] = "The Catcher in the Rye";
    judul_buku[1] = "Catch-22";
    judul_buku[2] = "To Kill a Mockingbird";
    judul_buku[3] = "1984";
    judul_buku[4] = "Brave New World";

    pengarang[0] = "J.D. Salinger";
    pengarang[1] = "Joseph Heller";
    pengarang[2] = "Harper Lee";
    pengarang[3] = "George Orwell";
    pengarang[4] = "Aldous Huxley";

    penerbit[0] = "Little, Brown and Company";
    penerbit[1] = "Simon & Schuster";
    penerbit[2] = "Harper & Row";
    penerbit[3] = "Secker and Warburg";
    penerbit[4] = "Chatto & Windus";

    tebal_halaman[0] = 277;
    tebal_halaman[1] = 453;
    tebal_halaman[2] = 281;
    tebal_halaman[3] = 328;
    tebal_halaman[4] = 199;

    harga_buku[0] = 9.99;
    harga_buku[1] = 12.99;
    harga_buku[2] = 7.99;
    harga_buku[3] = 10.99;
    harga_buku[4] = 8.99;

    // Menampilkan data (mirip dengan kode sebelumnya)
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku Favorit Saya" << endl;
        cout << "\tJudul Buku : " << judul_buku[i] << endl;
        cout << "\tPengarang : " << pengarang[i] << endl;
        cout << "\tPenerbit : " << penerbit[i] << endl;
        cout << "\tTebal Halaman: " << tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << harga_buku[i] << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/662124fc-e02f-4550-8979-d21e979ceba6)

Perubahan dari ```struct``` menjadi ```array``` memberikan akses data yang mudah dan fleksibilitas manipulasi. Akses data dapat dilakukan dengan mudah menggunakan indeks numerik, seperti judul_buku untuk mengakses buku ketiga. ```struct```, sebaliknya, memerlukan nama anggota untuk mengakses data, seperti favorit.judul_buku untuk mengakses buku ketiga. Selain itu, ```array``` memungkinkan penambahan dan penghapusan elemen dengan fungsi ```push_back()``` dan ```pop_back()``` yang mudah, sedangkan struct memerlukan penambahan dan penghapusan manual anggota yang mungkin rumit. ```Array``` juga mempunyai keterbatasan bahwa semua elemen harus memiliki tipe data yang sama, sedangkan ```struct``` memungkinkan elemen memiliki tipe data yang berbeda, memungkinkan fleksibilitas data.

## Kesimpulan

Struktur atau struct adalah kumpulan variabel dengan tipe data yang berbeda, digunakan untuk mengelompokkan informasi yang berkaitan. Struktur dapat memiliki struktur lain di dalamnya (nested struct). Struktur mirip dengan array, tetapi elemennya memiliki tipe data yang berbeda dan diakses dengan nama variabel, bukan indeks.

## Referensi
[1] A. Sindar, Struktur Data Dan Algoritma, no. December. 2018.
