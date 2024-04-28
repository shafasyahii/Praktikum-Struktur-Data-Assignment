# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
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

Kode di atas digunakan untuk 

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

Kode di atas 

## Kesimpulan

Tipe data digunakan untuk mengklasifikasikan berbagai jenis data. Tiga jenis tipe data yang umum digunakan yaitu tipe data primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman, contohnya int, float, char, dan bool. Tipe data abstrak merupakan suatu tipe data buatan diri sendiri sesuai keinginan, yang dapat diimplementasikan menggunakan struct atau class. Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel, contohnya array, vector, dan map.

## Referensi
[1] M. P. Putri et al., Algoritma Dan Struktur Data. 2022.
[2] Warno, “Pembelajaran Pemrograman Bahasa Java Dan Arti Keyword,” Pembelajaran Pemrograman Bhs. Java Dan Arti Keyword, vol. 8, no. 1, pp. 40–51, 2020.
[3] D. Rosadi, “ADT (Abstract Data Type) C++,” medium.com. Accessed: Mar. 10, 2024. [Online]. Available: https://medium.com/@111202214191/adt-abstract-data-type-c-4cdcf4441d8c
[4] R. Muliono, “ABSTRACT DATA TYPE (ADT),” blog.uma.ac.id. Accessed: Mar. 10, 2024. [Online]. Available: https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
