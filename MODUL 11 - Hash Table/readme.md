# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Linked list adalah struktur data linier yang terdiri dari simpul-simpul yang saling terhubung melalui pointer. Setiap simpul menyimpan data dan alamat (pointer) ke simpul berikutnya dalam urutan. Terdapat beberapa jenis linked list, antara lain: single linked list, double linked list, circular list [1].

#### 1. Single Linked List
Single Linked List adalah sekumpulan node yang saling terhubung dengan node lain melalui sebuah pointer. Rangkaian single linked list dimulai dengan sebuah head yang menyimpan alamat awal dan diakhiri dengan node yang mengarahkan pointer ke null.

Dalam single linked list, setiap node memiliki field yang berisi pointer ke node berikutnya, serta field yang berisi data. Node terakhir menunjuk ke null, yang digunakan sebagai kondisi berhenti saat membaca isi linked list. Keuntungan dari struktur dinamis ini adalah kemampuannya untuk menambah atau mengurangi elemen dengan mudah, berbeda dengan array yang memiliki ukuran tetap.

#### 2. Double Linked List
Double Linked List (dikenal juga sebagai Doubly Linked List) adalah jenis linked list yang memiliki dua pointer. Dalam struktur ini, setiap simpul (node) memiliki dua arah penunjuk: satu menunjuk ke simpul selanjutnya (next), dan yang lainnya menunjuk ke simpul sebelumnya (prev). Berbeda dengan single linked list, doubly linked list memungkinkan kita untuk melintasinya secara dua arah.

Beberapa karakteristik dari double linked list:

1. Setiap simpul memiliki dua pointer: next dan prev.
2. Pada simpul head, pointer prev akan bernilai NULL, karena simpul head adalah simpul pertama.
3. Pada simpul tail, pointer next akan menunjuk ke NULL sebagai penanda data terakhir.

#### 3. Circular List
Circular list adalah bentuk lain dari linked list yang memberikan fleksibilitas dalam melewatkan elemen. Circular list bisa berupa single linked list atau double linked list, tetapi tidak mempunyai tail. Pada circular list, pointer next dari elemen terakhir menunjuk ke elemen pertama dan bukan menunjuk NULL. Pada double linked circular list, pointer prev dari elemen pertama menunjuk ke elemen terakhir. susunan dari single linked circular list, hanya menangani link dari elemen terakhir kembali ke elemen pertama [2].

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

### 1.	1.	Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. 
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

Kode di atas digunakan untuk 

## Kesimpulan

Linked List adalah struktur data linier yang terdiri dari simpul-simpul yang saling terhubung melalui pointer, dengan Single Linked List sebagai jenis paling sederhana yang memiliki pointer ke node berikutnya dan field untuk data, Double Linked List yang memiliki dua pointer untuk melintasi secara dua arah, dan Circular List yang memberikan fleksibilitas dalam melewatkan elemen dengan pointer next dari elemen terakhir menunjuk ke elemen pertama.

## Referensi
[1] M. Erkamim et al., Buku Ajar Algoritma Dan Struktur Data, no. January. 2024.

[2] A. Sindar, Struktur Data Dan Algoritma, no. December. 2018.