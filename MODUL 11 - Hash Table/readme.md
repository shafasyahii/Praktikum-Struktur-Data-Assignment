# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Tabel hash adalah sebuah cara untuk menyimpan suatu data pada memori ke dalam baris-baris dan kolom-kolom sehingga membentuk tabel yang dapat diakses dengan cepat [1]. Setiap sel yang merupakan pertemuan antara baris dan kolom di dalam tabel hash dimana data diarsipkan disebut dengan slot [2]. Sebuah tabel hash dapat dibuat dari dua bagian, yaitu sebuah larik atau array dan sebuah fungsi untuk memetakan, yang disebut dengan fungsi hash atau hash function. Fungsi hash adalah pemetaan ke dalam larik sesuai dengan kunci-kunci yang diberikan, dengan kata lain fungsi hash mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel atau larik yang telah disediakan [3].

Algoritma Hash dapat melakukan proses tambah, hapus dan pencarian dalam waktu yang konstan [4]. Waktu konstan ini juga disebut sebagai kekompleksan waktu O(1). Teknik Hash merupakan suatu metode yang secara langsung mengakses data record dalam suatu tabel dengan melakukan penghitungan pada key yang menjadi alamat record pada tabel. Key merupakan suatu data yang unik dapat berupa nomor atau karakter string [5]. 

Hash table menggunakan memori penyimpanan utama berbentuk array dengan tambahan algoritma untuk mempercepat pemrosesan data. Pada intinya hash table merupakan penyimpanan data menggunakan key value yang didapat dari nilai data itu sendiri. Dengan key value tersebut didapat hash value. Jadi hash function merupakan suatu fungsi sederhana untuk mendapatkan hash value dari key value suatu data. Yang perlu diperhatikan untuk membuat hash function adalah:

- ukuran array/table size(m),
- key value/nilai yang didapat dari data(k),
- hash value/hash index/indeks yang dituju(h).

### 1. Fungsi
Fungsi hash membuat pemetaan antara kunci dan nilai, hal ini dilakukan melalui penggunaan rumus matematika yang dikenal sebagai fungsi hash. Hasil dari fungsi hash disebut sebagai nilai hash atau hash. Nilai hash adalah representasi dari string karakter asli tetapi biasanya lebih kecil dari aslinya.

### 2. Operasi
Di C++, operasi tabel hash melibatkan berbagai tugas untuk penanganan data yang efisien:

- Insertion: Menambahkan pasangan nilai kunci ke tabel.
- Search: Menemukan nilai menggunakan kunci yang sesuai.
- Deletion: Menghapus pasangan nilai kunci sesuai kebutuhan.
- Resizing: Menyesuaikan ukuran tabel untuk mengoptimalkan kinerja.
- Collision Handling: Mengelola situasi ketika beberapa kunci dipetakan ke indeks yang sama.
- Load Factor Maintenance: Memastikan keseimbangan optimal antara elemen dan ukuran tabel.
- Traversal: Mengulangi pasangan nilai kunci untuk mengakses atau memproses data.
- Clearing: Mengosongkan tabel hash dengan menghapus semua elemen.

### 3. Collison
Berikut contoh penggunaan hash table dengan hash function sederhana yaitu memodulus key value dengan ukuran array : h = k (mod m)

Misal kita memiliki array dengan ukuran 13, maka hash function : h = k (mod 13).

Dengan hash function tersebut didapat :

k	H
7	7
13	0
25	12
27	1
39	0
Perhatikan range dari h untuk sembarang nilai k.

Maka data 7 akan disimpan pada index 7, data 13 akan disimpan pada index 0, dst..

Untuk mencari kembali suatu data, maka kita hanya perlu menggunakan hash function yang sama sehingga mendapatkan hash index yang sama pula.

Misal : mencari data 25 → h = 25 (mod 13) = 12

Namun pada penerapannya, seperti contoh di atas terdapat tabrakan (collision) pada k = 13 dan k = 39. Collision berarti ada lebih dari satu data yang memiliki hash index yang sama, padahal seperti yang kita ketahui, satu alamat / satu index array hanya dapat menyimpan satu data saja.

Untuk meminimalkan collision gunakan hash function yang dapat mencapai seluruh indeks/alamat. Dalam contoh di atas gunakan m untuk me-modulo k. Perhatikan bila kita menggunakan angka m untuk me-modulo k maka pada indeks yang lebih besar dari dan sama dengan m di hash table tidak akan pernah terisi (memori yang terpakai semakin kecil), kemungkinan terjadi collision juga semakin besar.

Karena memori yang terbatas dan untuk masukan data yang belum diketahui tentu collision tidak dapat dihindari.

Berikut ini cara-cara yang digunakan untuk mengatasi collision :

1.   Closed hashing (Open Addressing)

Close hashing menyelesaikan collision dengan menggunakan memori yang masih ada tanpa menggunakan memori diluar array yang digunakan. Closed hashing mencari alamat lain apabila alamat yang akan dituju sudah terisi oleh data. 3 cara untuk mencari alamat lain tersebut :

Ø Linear Probing
Apabila telah terisi, linear probing mencari alamat lain dengan bergeser 1 indeks dari alamat sebelumnya hingga ditemukan alamat yang belum terisi data, dengan rumus

(h+1) mod m.

Ø Quadratic Probing
Quadratic Probing mencari alamat baru untuk ditempati dengan proses perhitungan kuadratik yang lebih kompleks. Tidak ada formula baku pada quadratic probing ini,anda dapat menentukan sendiri formula yang akan digunakan.

Contoh formula quadratic probing untuk mencari alamat baru:

h,(h+i2)mod m,(h-i2)mod m, … ,(h+((m-1)/2)2)mod m, (h-((m-1)/2)2)mod m

dengan i = 1,2,3,4, … , ((m-1)/2)

Mksud formula di atas adalah jika alamat h telah terisi, maka alamat lain yang digunakan adalah (h+1)mod m, jika telah terisi gunakan alamat (h-1)mod m,  jika telah terisi gunakan alamat (h+4)mod m, jika telah terisi gunakan alamat (h-4)mod m, dan seterusnya.

Jadi jika m=23,maka nilai maksimal i adalah : ((23-1)/2)=11.

1. Closed Hashing
- Linear Probing
Pada saat terjadi collision, maka akan mencari posisi yang kosong di bawah tempat terjadinya collision, jika masih penuh terus ke bawah, hingga ketemu tempat yang kosong. Jika tidak ada tempat yang kosong berarti HashTable sudah penuh.
- Quadratic Probing
Penanganannya hampir sama dengan metode linear, hanya lompatannya tidak satu-satu, tetapi quadratic ( 12, 22, 32, 42, ... )
- Double Hashing
Pada saat terjadi collision, terdapat fungsi hash yang kedua untuk menentukan posisinya kembali.

2. Open hashing (Separate Chaining)
Pada dasarnya separate chaining membuat tabel yang digunakan untuk proses hashing menjadi sebuah array of pointer yang masing-masing pointernya diikuti oleh sebuah linked list, dengan chain (mata rantai) 1 terletak pada array of pointer, sedangkan chain 2 dan seterusnya berhubungan dengan chain 1 secara memanjang.

Kelemahan dari open hashing adalah bila data menumpuk pada satu/sedikit indeks sehingga terjadi linked list yang panjang.

## Guided 

### 1. Guided I

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```
Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array. 

### 2. Guided II

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
Pada program di atas, class HashNode merepresentasikan setiap node dalam hash table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap digunakan untuk mengimplementasikan struktur hash table dengan menggunakan vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi remove digunakan untuk menghapus data dari hash table, dan fungsi searchByName digunakan untuk mencari nomor telepon dari karyawan dengan nama yang diberikan.

## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. 
Dengan ketentuan :
a.	Setiap mahasiswa memiliki NIM dan nilai.
b.	Program memiliki tampilan pilihan menu berisi poin C.
c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    int nilai;
};

// Hash table untuk menyimpan data mahasiswa
unordered_map<string, Mahasiswa> hashTable;

// Fungsi untuk menambahkan data baru
void tambahData() {
    string nim;
    int nilai;

    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    hashTable[nim] = Mahasiswa{nim, nilai};
    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus data
void hapusData() {
    string nim;

    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> nim;

    if (hashTable.find(nim) != hashTable.end()) {
        hashTable.erase(nim);
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencari data berdasarkan NIM
void cariDataNIM() {
    string nim;

    cout << "Masukkan NIM yang akan dicari: ";
    cin >> nim;

    if (hashTable.find(nim) != hashTable.end()) {
        cout << "Data ditemukan!" << endl;
        cout << "NIM: " << hashTable[nim].nim << endl;
        cout << "Nilai: " << hashTable[nim].nilai << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mencari data berdasarkan rentang nilai (80 – 90)
void cariDataRentangNilai() {
    int nilaiAwal = 80;
    int nilaiAkhir = 90;

    cout << "Data dengan nilai dalam rentang " << nilaiAwal << " - " << nilaiAkhir << ":" << endl;

    for (const auto& pair : hashTable) {
        if (pair.second.nilai >= nilaiAwal && pair.second.nilai <= nilaiAkhir) {
            cout << "NIM: " << pair.first << endl;
            cout << "Nilai: " << pair.second.nilai << endl;
        }
    }
}

int main() {
    int pilihan;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambahkan data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Cari data berdasarkan NIM" << endl;
        cout << "4. Cari data berdasarkan rentang nilai" << endl;
        cout << "5. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                cariDataNIM();
                break;
            case 4:
                cariDataRentangNilai();
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-29 141735](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/a2b79113-15bc-458f-b1e9-0a50aafe7ccd)

Berikut adalah penjelasan lebih detail untuk masing-masing bagian:

1. ```#include <iostream>```: Melampirkan library input/output untuk menggunakan fungsi-fungsi input/output seperti ```cout```, ```cin```, ```endl```.
2. ```#include <string>```: Melampirkan library string untuk menggunakan tipe data string.
3. ```#include <vector>```: Melampirkan library vector, yang digunakan dalam kode ini tetapi tidak digunakan secara efektif.
4. ```#include <unordered_map>```: Melampirkan library unordered_map (hash table) yang digunakan untuk menyimpan data mahasiswa.
5. ```using namespace std;```: Menggunakan namespace std supaya tidak perlu mengetik ```std::``` untuk setiap elemen yang berasal dari namespace tersebut.
6. ```struct Mahasiswa { ... };```: Struktur yang digunakan untuk menyimpan data mahasiswa, yaitu NIM dan nilai.
7. ```unordered_map<string, Mahasiswa> hashTable;```: Hash table yang digunakan untuk menyimpan data mahasiswa.
8. ```tambahData()```, ```hapusData()```, ```cariDataNIM()```, dan ```cariDataRentangNilai()```: Fungsi-fungsi CRUD untuk mengelola data mahasiswa.
9. ```main()```: Fungsi utama yang akan dijalankan. Dalam fungsi ini, terdapat perulangan yang akan mengulangi menu hingga pengguna memilih untuk keluar.

Dalam kode ini, pengguna akan diminta untuk memilih menu yang tersedia, dan kemudian akan diarahkan ke fungsi yang sesuai. Fungsi-fungsi tersebut akan melakukan operasi CRUD (Create, Read, Update, Delete) pada data mahasiswa yang disimpan dalam hash table.

## Kesimpulan

Hash table adalah struktur data yang powerful dan efisien untuk menyimpan data secara asosiatif. Hash table menawarkan akses data yang cepat dan mudah, dengan berbagai operasi yang dapat dilakukan dengan waktu rata-rata O(1). Namun, hash table perlu diimplementasikan dengan hati-hati untuk menghindari collision yang sering dan memastikan kinerja yang optimal.

#### Kelebihan hash table:

- Akses data yang cepat dan efisien.
- Mudah digunakan dan diimplementasikan.
- Serbaguna dan dapat digunakan untuk berbagai jenis data.

#### Kekurangan hash table:

- Kinerja dapat menurun jika terjadi collision yang sering.
- Membutuhkan fungsi hash yang baik untuk meminimalkan collision.
- Membutuhkan memori tambahan untuk menyimpan tabel hash.

## Referensi
[1] Barnes & Noble, Hash Tables, *Sparknotes*, http://www.sparknotes.com/ cs/searching/hashtables/section1.html.

[2] Department of Computer Science, the University of Auckland, *Data Structures and Algorithm*, http://www.cs.auckland.ac.nz/software/ AlgAnim/hash_tables.html.

[3] J. Prestiliano, “Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data,” J. Teknol., vol. 4, no. 1, pp. 41–56, 2007.

[4] M.A. Weiss, *Data Structures and Algorithm Analysis in Java*, 3rd ed. Pearson Education, USA, 2012.

[5] V. Mutiawani, “HASHTABLE SEBAGAI ALTERNATIF DARI ALGORITMA PENCARIAN BINER PADA APLIKASI E-ACESIA,” Informatika, 2014.