# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Rekursif adalah sebuah algoritma yang berisi pemanggilan dirinya sendiri sehingga menghasilkan looping. Harus ada batasan di dalam rekursif sehingga looping dapat dibatalkan, jika tidak maka akan terjadi infinity loop dan dapat menyebabkan memori penuh [1]. Rekursi adalah suatu proses dengan salah satu langkah dalam prosedur tersebut menjalankan prosedur itu sendiri [2]. Dalam pemrograman komputer, rekursi dicontohkan saat sebuah fungsi didefinisikan dalam bentuk sederhana, bahkan versi terkecil dari dirinya. Solusi dari permasalahan kemudian dirancang dengan menggabungkan solusi-solusi yang didapat dari versi sederhana dari permasalahan [3].

![Screenshot 2024-06-07 105552](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/0fce1228-9ab9-49bb-a0d9-51bba4708044)

Fungsi rekursif merupakan salah satu jenis relasi. Misalkan terdapat himpunan A sebagai domain dan himpunan B seabgai codomain, maka suatu relasi disebut fungsi jika relasi tersebut menghubungkan setiap elemen di dalam A ke tepat satu elemen di dalam B [4]. Fungsi rekursif adalah fungsi yang mengacu pada dirinya sendiri. Fungsi rekursif disusun atas dua bagian, yaitu basis dan rekurens. Basis berisi nilai awal yang tidak mengacu pada dirinya sendiri. Bagian ini berfungsi untuk memberikan nilai yang terdefinisi pada fungsi rekursif dan sekaligus menghentikan proses rekursi. Rekurens merupakan bagian fungsi yang mendefinisikan argumen fungsi dalam terminologi dirinya sendiri. Setiap kali fungsi tersebut melakukan bagian rekurens maka argumen dari fungsi tersebut harus lebih dekat pada basisnya [5].

Adapun aturan rekursif sebagai berikut [6]:

1. Punya kasus dasar
- Kasus yang sangat sederhana yang dapat memproses input tanpa perlu melakukan rekursif (memanggil method) lagi
2. Rekursif mengarah ke kasus dasar
3. “You gotta believe”. Asumsikan rekursif bekerja benar. Pada proses pemanggilan rekursif, asumsikan bahwa pemanggilan rekursif (untuk problem yang lebih kecil) adalah benar.
Contoh: ```pangkatRekursif (x, n)```
- Asumsikan: ```pangkatRekursif (x, n - 1)``` menghasilkan nilai yang benar.
- Nilai tersebut harus diapakan sehingga menghasilkan nilai ```pangkatRekursif (x, n)``` yang benar?
- Jawabannya: dikalikan dengan ```x```
4. Aturan penggabungan: Hindari duplikasi pemanggilan rekursif untuk sub-problem yang sama.

## Guided 

### 1. Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n-1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```
Kode di atas digunakan untuk membuat sebuah fungsi rekursif yang menghitung mundur dari sebuah nilai tertentu hingga mencapai 0.

Berikut adalah penjelasan rinci tentang kodingan tersebut:

1. ```#include <iostream>```: Baris ini digunakan untuk mengincludekan library input/output standar C++ yang memungkinkan kita untuk menggunakan fungsi-fungsi seperti ```cout``` untuk menampilkan output ke layar.
2. ```using namespace std;```: Baris ini digunakan untuk mengimport namespace standar C++ yang memungkinkan kita untuk menggunakan nama-nama fungsi dan variabel tanpa harus menggunakan prefix ```std::```.
3. ```void countdown(int n) { ... }```: Fungsi ini bernama ```countdown``` dan memiliki parameter ```n``` yang bertipe integer. Fungsi ini akan menghitung mundur dari nilai ```n``` hingga mencapai 0.
4. ```if (n == 0) { return; }```: Baris ini digunakan untuk menghentikan rekursi jika nilai ```n``` sudah mencapai 0. Jika nilai ```n``` sudah 0, maka fungsi akan mengembalikan nilai tanpa melakukan apa-apa lagi.
5. ```cout << n << " ";```: Baris ini digunakan untuk menampilkan nilai ```n``` ke layar, diikuti oleh spasi.
6. ```countdown(n-1);```: Baris ini digunakan untuk memanggil fungsi ```countdown``` lagi dengan nilai ```n-1```. Ini akan membuat fungsi menghitung mundur dari nilai ```n-1``` hingga mencapai 0.
7. ```int main() { ... }```: Fungsi main adalah fungsi utama program yang akan dijalankan pertama kali.
8. ```cout << "Rekursi Langsung: ";```: Baris ini digunakan untuk menampilkan teks "Rekursi Langsung: " ke layar.
9. ```countdown(5);```: Baris ini digunakan untuk memanggil fungsi ```countdown``` dengan nilai awal 5.
10. ```cout << endl;```: Baris ini digunakan untuk menampilkan baris baru ke layar.
11. ```return 0;```: Baris ini digunakan untuk mengembalikan nilai 0 ke sistem, yang menandakan bahwa program telah selesai dijalankan dengan sukses.

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n-1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
Kode di atas digunakan untuk membuat dua fungsi rekursif yang saling memanggil satu sama lain, yaitu ```functionA``` dan ```functionB```. Fungsi-fungsi ini akan menghitung mundur dari sebuah nilai tertentu hingga mencapai 0, tetapi dengan cara yang tidak langsung.

Berikut adalah penjelasan rinci tentang kodingan tersebut:

1. ```#include <iostream>```: Baris ini digunakan untuk mengincludekan library input/output standar C++ yang memungkinkan kita untuk menggunakan fungsi-fungsi seperti ```cout``` untuk menampilkan output ke layar.
2. ```using namespace std;```: Baris ini digunakan untuk mengimport namespace standar C++ yang memungkinkan kita untuk menggunakan nama-nama fungsi dan variabel tanpa harus menggunakan prefix ```std::```.
3. ```void functionB(int n);```: Deklarasi fungsi ```functionB``` yang akan dipanggil oleh ```functionA```.
4. ```void functionA(int n) {... }```: Fungsi ```functionA``` memiliki parameter ```n``` yang bertipe integer. Fungsi ini akan menghitung mundur dari nilai ```n``` hingga mencapai 0, tetapi dengan cara yang tidak langsung.
5. ```if (n > 0) {... }```: Baris ini digunakan untuk menghentikan rekursi jika nilai ```n``` sudah mencapai 0 atau kurang dari 0.
6. ```cout << n << " ";```: Baris ini digunakan untuk menampilkan nilai ```n``` ke layar, diikuti oleh spasi.
7. ```functionB(n-1);```: Baris ini digunakan untuk memanggil fungsi ```functionB``` dengan nilai ```n-1```. Ini akan membuat fungsi ```functionB``` menghitung mundur dari nilai ```n-1``` hingga mencapai 0.
8. ```void functionB(int n) {... }```: Fungsi ```functionB``` memiliki parameter ```n``` yang bertipe integer. Fungsi ini akan menghitung mundur dari nilai ```n``` hingga mencapai 0, tetapi dengan cara yang tidak langsung.
9. ```if (n > 0) {... }```: Baris ini digunakan untuk menghentikan rekursi jika nilai ```n``` sudah mencapai 0 atau kurang dari 0.
10. ```cout << n << " ";```: Baris ini digunakan untuk menampilkan nilai ```n``` ke layar, diikuti oleh spasi.
11. ```functionA(n / 2);```: Baris ini digunakan untuk memanggil fungsi ```functionA``` dengan nilai ```n / 2```. Ini akan membuat fungsi ```functionA``` menghitung mundur dari nilai ```n / 2``` hingga mencapai 0.
12. ```int main() {... }```: Fungsi main adalah fungsi utama program yang akan dijalankan pertama kali.
13. ```int num = 5;```: Deklarasi variabel ```num``` dengan nilai awal 5.
14. ```cout << "Rekursif Tidak Langsung: ";```: Baris ini digunakan untuk menampilkan teks "Rekursif Tidak Langsung: " ke layar.
15. ```functionA(num);```: Baris ini digunakan untuk memanggil fungsi ```functionA``` dengan nilai awal 5.
16. ```return 0;```: Baris ini digunakan untuk mengembalikan nilai 0 ke sistem, yang menandakan bahwa program telah selesai dijalankan dengan sukses.

## Unguided

### 1.	Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
  if (n == 0) {
    return 1; // Kasus dasar: faktorial dari 0 adalah 1
  } else {
    return n * faktorial(n - 1); // Rekursi: n! = n * (n-1)!
  }
}

int main() {
  int n;

  cout << "Masukkan bilangan bulat positif: ";
  cin >> n;

  if (n < 0) {
    cout << "Faktorial tidak terdefinisi untuk bilangan negatif." << endl;
  } else {
    cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
  }

  return 0;
}
```
#### Output:
![Screenshot 2024-06-07 111530](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/63203f6c-4095-4a26-be3a-f67e93635dcc)

Kode di atas digunakan untuk membuat sebuah program yang menghitung faktorial dari sebuah bilangan bulat positif menggunakan fungsi rekursif.

Berikut adalah penjelasan rinci tentang kodingan tersebut:

1. ```#include <iostream>```: Baris ini digunakan untuk mengincludekan library input/output standar C++ yang memungkinkan kita untuk menggunakan fungsi-fungsi seperti ```cout``` dan ```cin``` untuk menampilkan output ke layar dan membaca input dari pengguna.
2. ```using namespace std;```: Baris ini digunakan untuk mengimport namespace standar C++ yang memungkinkan kita untuk menggunakan nama-nama fungsi dan variabel tanpa harus menggunakan prefix ```std::```.
3. ```int faktorial(int n) {... }```: Fungsi ```faktorial``` memiliki parameter ```n``` yang bertipe integer. Fungsi ini akan menghitung faktorial dari nilai ```n```.
4. ```if (n == 0) {... }```: Baris ini digunakan untuk menghandle kasus dasar, yaitu jika nilai ```n``` adalah 0. Faktorial dari 0 adalah 1.
5. ```return n * faktorial(n - 1);```: Baris ini digunakan untuk menghitung faktorial dari nilai ```n``` dengan cara rekursif. Faktorial dari ```n``` adalah ```n``` dikali faktorial dari ```n-1```.
6. ```int main() {... }```: Fungsi ```main``` adalah fungsi utama program yang akan dijalankan pertama kali.
7. ```int n;```: Deklarasi variabel ```n``` yang akan digunakan untuk menyimpan nilai bilangan bulat positif yang diinput oleh pengguna.
8. ```cout << "Masukkan bilangan bulat positif: ";```: Baris ini digunakan untuk menampilkan teks "Masukkan bilangan bulat positif: " ke layar.
9. ```cin >> n;```: Baris ini digunakan untuk membaca input dari pengguna dan menyimpannya ke dalam variabel ```n```.
10. ```if (n < 0) {... }```: Baris ini digunakan untuk menghandle kasus jika nilai ```n``` adalah negatif. Faktorial tidak terdefinisi untuk bilangan negatif.
11. ```cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;```: Baris ini digunakan untuk menampilkan hasil faktorial dari nilai ```n``` ke layar.
12. ```return 0;```: Baris ini digunakan untuk mengembalikan nilai 0 ke sistem, yang menandakan bahwa program telah selesai dijalankan dengan sukses.

Jika kita jalankan program ini, maka program akan meminta pengguna untuk memasukkan bilangan bulat positif. Kemudian, program akan menghitung faktorial dari nilai tersebut menggunakan fungsi rekursif dan menampilkan hasilnya ke layar.

### 2.	Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial (fungsi pembantu)
int faktorialHelper(int n, int acc) {
    if (n == 0) {
        return acc; // mengembalikan nilai akumulasi
    } else {
        return faktorialHelper(n - 1, acc * n); // Rekursi: mengalikan n dengan akumulasi dan melanjutkan rekursi
    }
}

int main() {
    int n;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Faktorial tidak terdefinisi untuk bilangan negatif." << endl;
    } else {
        cout << "Faktorial dari " << n << " adalah: " << faktorialHelper(n, 1) << endl; // Memanggil fungsi pembantu dengan nilai awal akumulasi 1
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-06-07 111600](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/0a67ff6f-9a99-451f-8839-37f413a497ca)

Kode di atas merupakan bentuk rekursif tidak langsung dari soal nomor satu. Jika kita jalankan program ini, maka program akan meminta pengguna untuk memasukkan bilangan bulat positif. Kemudian, program akan menghitung faktorial dari nilai tersebut menggunakan fungsi rekursif dengan bantuan fungsi pembantu dan menampilkan hasilnya ke layar.

## Kesimpulan

Rekursif adalah teknik pemrograman yang memungkinkan suatu fungsi untuk memanggil dirinya sendiri. Hal ini memungkinkan penyelesaian masalah yang kompleks dengan cara memecahnya menjadi sub-masalah yang lebih kecil dan serupa. Namun, penting untuk memahami cara kerjanya dengan baik untuk menghindari infinite loop dan memaksimalkan manfaatnya.

#### Karakteristik utama rekursif:
- Memiliki kasus dasar: Kondisi yang menghentikan proses rekursif dan mengembalikan nilai.
- Memiliki kasus rekursif: Memanggil fungsi itu sendiri dengan parameter yang lebih kecil, mengantarkannya ke kasus dasar.

#### Kegunaan rekursif:
- Menyederhanakan kode untuk masalah yang kompleks.
- Mempermudah pemahaman dan pembacaan kode.
- Menghindari penggunaan loop eksplisit.

#### Kelemahan rekursif:
- Risiko infinite loop jika tidak ada kasus dasar yang jelas.
- Membutuhkan memori stack yang lebih banyak dibandingkan loop iteratif.

## Referensi
[1] M. Ahmad. (2016, 30 Desember). Memahami Cara Kerja Fungsi Rekursif. Diakses pada 27 Mei 2024, dari https://www.petanikode.com/fungsi-rekursif/.

[2] F. A. T. Tobing and A. Chandra, “Analisis Perbandingan Fibonacci dengan Iterasi dan Rekursi Terhadap Efektifitas Waktu,” J. Sains dan Teknol. Widya, vol. 1, no. 2, pp. 188–195, 2022, [Online]. Available: https://jurnal.amikwidyaloka.ac.id/index.php/jstekwid

[3] https://id.m.wikipedia.org/wiki/Rekursi. Diakses pada 27 Mei 2024

[4] R. Munir, *Struktur Diskrit*, ITB, 2008

[5] S. Herlambang, “Implementasi Fungsi Rekursif Dalam Algoritma dan Perbandingannya dengan Fungsi Iteratif,” p. 6, 2018, [Online]. Available: https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2008-2009/Makalah2008/Makalah0809-079.pdf

[6] S. Setiawan, R. Manurung, and A. Azurat, “Struktur Data dan Algoritma Dasar-dasar Rekursif Devide and Conquer Mengulang : Maximum Contiguous subsequence,” 2010.
