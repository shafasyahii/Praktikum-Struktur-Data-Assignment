# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Array
Array adalah kumpulan variabel yang memiliki tipe data yang sama dan dapat menyimpan beberapa nilai dalam satu variabel. Array merupakan tipe data terstruktur dalam pemrograman, yang memungkinkan untuk menyimpan data atau referensi objek dalam jumlah banyak dan terindeks. Sehingga sejumlah variabel dapat menggunakan nama yang sama [web]. Dengan menggunakan array, kita dapat menghindari penggunaan variabel yang terlalu banyak. Adapun bentuk array berdasarkan dimensinva terbagi menjadi lima, yaitu Array berdimensi satu, array berdimensi dua, array multidimensi, array empat dimensi, dan array lima dimensi.

#### 1. Array Satu Dimensi
Array satu dimensi merupakan sebuah variabel yang menyimpan sekumpulan elemen dengan tipe data homogen dan hanya memiliki satu indeks [jurnal logika]. Elemen pertama ditandai dengan indeks 0, elemen kedua di indeks 1, dan seterusnya. Array satu dimensi ini mudah digunakan dan mudah dibaca sehingga membuat array jenis ini menjadi yang paling umum digunakan. Untuk mendeklarasikan sebuah array satu dimensi kita menggunakan tanda ```[ ]``` (bracket). Bentuk umum pendeklarasian array satu dimensi adalah sebagai berikut: 
```
tipe_data nama_array[jumlah_elemen];
```
Contoh:
```
int Nilai[10];
```
Kita dapat memberikan nilai pada elemen array saat pendeklarasian. Misalnya:
```
int Nilai[10] = {1, 2, 4, 5, 3,7, 6, 9, 8, 10};
```
Dalam contoh ini, kita telah memesan tempat pada memori komputer sebanyak 10 tempat (indeks 0 hingga 9) dan mengisinya dengan nilai-nilai yang diberikan.

#### 2. Array Dua Dimensi
Array dua dimensi adalah array yang terdiri dari n buah baris dan m buah kolom, atau array dua dimensi juga biasa disebut sebagai array yang mempunyai dua subskrip, yaitu baris dan kolom [web materidosen]. Untuk mendeklarasikan variabel array dua dimensi, harus menentukan nama array diikuti oleh dua tanda kurung dimana indeks kedua adalah set kedua tanda kurung kotak. Indeks pertama menunjukkan baris, dan indeks kedua menunjukkan kolom [jurnal struktur].
Contoh deklarasi array dua dimensi: 
```
int bilangan[2][2];
``` 
Di sini, ```bilangan``` adalah sebuah array dua dimensi yang berisi 4 elemen (2 x 2). Untuk mengakses setiap elemen array, kita menggunakan dua indeks, misalnya: 
```
bilangan[0][0] = 100;
bilangan[0][1] = 101;
bilangan[1][0] = 110;
bilangan[1][1] = 111;
```
Selain itu, kita juga bisa menginisialisasi nilai saat mendefinisikan array, seperti contoh berikut:
```
int matrix[2][3] = {
    {1, 2, 3},
    {7, 8, 9}
};
```

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
Kode di atas digunakan untuk mengimplementasikan input dan output array tiga dimensi. Program ini mendeklarasikan sebuah array tiga dimensi dengan ukuran 2x3x3 menggunakan ```int arr[2][3][3];```. 1. Selanjutnya, program meminta pengguna untuk memasukkan nilai elemen-elemen array. Dalam tiga loop bersarang, program mengambil input dari pengguna dan menyimpannya di dalam array. Setelah semua elemen dimasukkan, program mencetak nilai-nilai array tersebut dengan pesan ```Data Array[x][y][z] = nilai``` menggunakan loop yang serupa. Terakhir, program mencetak seluruh array dalam format yang lebih sederhana, hanya nilai-nilai array tanpa pesan tambahan.

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
Kode di atas digunakan untuk mencari nilai maksimum dari sebuah array dan lokasi/indeksnya. Pengguna diminta untuk memasukkan panjang array dan angka-angka ke dalam array. Setelah semua angka dimasukkan, program mencari nilai maksimum dan mencatat lokasi/indeksnya di mana nilai maksimum tersebut ditemukan. Terakhir, program akan menampilkan nilai maksimum dan lokasinya.

## Unguided

### 1.  Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/54d9ddfd-cd8e-4828-925d-e1d82e3185ef)

```C++
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int dataArray[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> dataArray[i];
    }

    cout << "Data Array: ";
    for(int i = 0; i < size; i++) {
        cout << dataArray[i] << " ";
    }

    cout << "\nNomor Genap: ";
    for(int i = 0; i < size; i++) {
        if(dataArray[i] % 2 == 0) {
            cout << dataArray[i] << " ";
        }
    }

    cout << "\nNomor Ganjil: ";
    for(int i = 0; i < size; i++) {
        if(dataArray[i] % 2 != 0) {
            cout << dataArray[i] << " ";
        }
    }

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/6a9b349d-7c92-4e1e-9530-3d864b0bdee0)

Kode di atas digunakan untuk mengelola data dalam bentuk array dan memisahkan elemen-elemen berdasarkan sifat genap atau ganjilnya. Program ini meminta pengguna untuk memasukkan ukuran array (jumlah elemen yang akan dimasukkan). Setelah mendapatkan ukuran array, program akan meminta pengguna memasukkan elemen-elemen array. Pengguna diminta memasukkan bilangan bulat sebanyak ukuran array yang telah ditentukan. Program akan memeriksa setiap elemen array. Jika elemen tersebut adalah bilangan genap (habis dibagi 2), maka program akan menampilkannya sebagai ```Nomor Genap```. Program juga akan memeriksa setiap elemen array. Jika elemen tersebut adalah bilangan ganjil (tidak habis dibagi 2), maka program akan menampilkannya sebagai ```Nomor Ganjil```. Setelah semua elemen array diperiksa, program akan mengakhiri eksekusi dan mengembalikan nilai 0.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Inputkan jumlah dimensi pertama dan kedua
    int dim1, dim2, dim3;
    cout << "Masukkan jumlah elemen dimensi pertama: ";
    cin >> dim1;
    cout << "Masukkan jumlah elemen dimensi kedua: ";
    cin >> dim2;
    cout << "Masukkan jumlah elemen dimensi ketiga: ";
    cin >> dim3;

    // Deklarasi array dengan ukuran yang diinputkan
    int arr[dim1][dim2][dim3];

    // Input elemen
    for (int x = 0; x < dim1; x++)
    {
        for (int y = 0; y < dim2; y++)
        {
            for (int z = 0; z < dim3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < dim1; x++)
    {
        for (int y = 0; y < dim2; y++)
        {
            for (int z = 0; z < dim3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < dim1; x++)
    {
        for (int y = 0; y < dim2; y++)
        {
            for (int z = 0; z < dim3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/9d44326e-c14d-4b33-84a4-0b8fc5101ec4)

Seperti pada guided satu, kode di atas adalah program untuk mengelola data dalam bentuk array tiga dimensi. Pengguna diminta memasukkan jumlah elemen untuk setiap dimensi pertama, kedua, dan ketiga. Setelah mendapatkan ukuran array, program mendeklarasikan array tiga dimensi dengan ukuran yang diinputkan. Kemudian, program meminta pengguna memasukkan elemen-elemen array. Pengguna diminta memasukkan bilangan bulat sebanyak elemen yang ada dalam array. Setelah semua elemen array dimasukkan, program akan menampilkan seluruh data array yang telah diinput. Data array ditampilkan dengan format ```Data Array[Dimensi1][Dimensi2][Dimensi3] = Nilai```. Pada tampilan array, program menampilkan elemen-elemen array dalam bentuk matriks tiga dimensi. Setiap elemen dipisahkan oleh spasi, dan setiap dimensi terpisah oleh baris baru.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
using namespace std;

int main()
{
    // Masukkan Array oleh user
    int n, i, valor;
    cout << "Masukkan panjang array: ";
    cin >> n;
    int array[n];

    cout << "Masukkan " << n << " angka:\n";
    for (i = 0; i < n; i++)
    {
        cout << "Angka ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    // Menentukan nilai maksimum, minimum, dan lokasi
    int max = array[0];
    int min = array[0];
    int max_loc = 0;
    int min_loc = 0;
    for (i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            max_loc = i;
        }
        if (array[i] < min)
        {
            min = array[i];
            min_loc = i;
        }
    }
    cout << "Nilai maksimum adalah " << max << " berada di index " << max_loc << endl;
    cout << "Nilai minimum adalah " << min << " berada di index " << min_loc << endl;

    // Menentukan nilai rata-rata
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += array[i];
    }
    double avg = (double)sum / n;
    cout << "Nilai rata-rata adalah " << avg << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/a6bc9ac1-5fbc-485b-9fc0-7a41c7ea0a6f)

Kode ini digunakan untuk mencari nilai maksimum, minimum, rata-rata, dan lokasi dari nilai-nilai yang dimasukkan oleh pengguna dalam array. Program ini dimulai dengan meminta pengguna untuk memasukkan panjang array (jumlah angka) dan menyimpannya ke dalam variabel ```n```. Setelah itu, pengguna diminta untuk memasukkan angka-angka yang akan dimasukkan ke dalam array. Kemudian program akan menentukan nilai maksimum dan minimum serta lokasi (index) dari nilai maksimum dan minimum di dalam array. Selanjutnya, program menghitung nilai rata-rata dari semua nilai yang dimasukkan pengguna. Terakhir, program akan menampilkan hasil dari nilai maksimum, minimum, dan rata-rata beserta lokasi-nya.

## Kesimpulan

Tipe data

## Referensi

