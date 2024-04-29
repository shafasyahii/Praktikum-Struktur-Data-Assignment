# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
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

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan operasi pada Single Linked List (SLL) non-circular, yaitu sebuah struktur data yang terdiri dari node-node yang terhubung satu sama lain melalui pointer. SLL non-circular berbeda dengan SLL circular karena tidak memiliki pointer yang mengarah ke node pertama ketika mencapai node terakhir.

Program ini terdiri dari beberapa fungsi yang digunakan untuk mengelola SLL. Fungsi ```init()``` digunakan untuk inisialisasi SLL dengan mengatur pointer ```head``` dan ```tail``` menjadi ```NULL```. Fungsi ```isEmpty()``` digunakan untuk mengecek apakah SLL masih kosong. Fungsi ```insertDepan(int nilai)``` dan ```insertBelakang(int nilai)``` digunakan untuk menambahkan data di depan dan belakang SLL, masing-masing. Fungsi ```hitungList()``` digunakan untuk menghitung jumlah node dalam SLL. Fungsi ```insertTengah(int data, int posisi)``` digunakan untuk menambahkan data di tengah SLL, sedangkan fungsi ```hapusDepan()```, ```hapusBelakang()```, dan ```hapusTengah(int posisi)``` digunakan untuk menghapus node di depan, belakang, dan tengah SLL, masing-masing. Fungsi ```ubahDepan(int data)```, ```ubahTengah(int data, int posisi)```, dan ```ubahBelakang(int data)``` digunakan untuk mengubah data di depan, tengah, dan belakang SLL, masing-masing. Fungsi ```clearList()``` digunakan untuk menghapus semua node dalam SLL. Fungsi tampil() digunakan untuk menampilkan isi SLL. Terakhir, fungsi ```main()``` digunakan untuk menguji operasi-operasi yang telah diimplementasikan.

### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan sebuah linked list yang dapat beroperasi secara double-ended, yaitu dapat menambahkan, menghapus, mengupdate, dan menghapus semua data dalam linked list. Kode ini terdiri dari dua kelas: ```Node``` dan ```DoublyLinkedList```. Kelas ```Node``` digunakan untuk mewakili setiap elemen dalam linked list, yang memiliki atribut ```data```, ```prev``` (pointer ke elemen sebelumnya), dan ```next``` (pointer ke elemen berikutnya). Kelas ```DoublyLinkedList``` digunakan untuk mengelola linked list secara keseluruhan. Kelas ini memiliki atribut ```head``` (pointer ke elemen pertama dalam linked list) dan ```tail``` (pointer ke elemen terakhir dalam linked list). Kelas ini juga memiliki beberapa metode untuk mengoperasikan linked list, seperti ```push``` untuk menambahkan elemen baru, ```pop``` untuk menghapus elemen pertama, ```update``` untuk mengupdate data elemen, ```deleteAll``` untuk menghapus semua elemen, dan ```display``` untuk menampilkan semua elemen dalam linked list. Dalam fungsi ```main()```, pengguna dapat memilih operasi yang ingin dilakukan terhadap linked list, seperti menambahkan data, menghapus data, mengupdate data, menghapus semua data, atau menampilkan data.

### 3. Linked List Non Circular

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus-> next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

//Tampilan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan Single Linked List Circular (SLLC). SLLC adalah struktur data yang terdiri dari node-node yang saling terhubung dengan pointer next, dan tidak memiliki pointer prev seperti dalam Double Linked List. SLLC memiliki beberapa operasi dasar seperti insert, delete, dan traversal. Program ini dapat diinisialisasi dengan fungsi ```init()```, yang mengatur ```head``` dan ```tail``` menjadi ```NULL```. Selain itu, program juga memiliki fungsi ```isEmpty()``` untuk mengecek apakah SLLC masih kosong atau tidak. Fungsi ```buatNode(string data)``` digunakan untuk membuat node baru dengan data yang diberikan. Program ini juga memiliki fungsi untuk menghitung jumlah node dalam SLLC, yaitu ```hitungList()```. Selain itu, program juga memiliki fungsi untuk menambahkan node baru di depan, tengah, dan belakang SLLC, yaitu ```insertDepan(string data)```, ```insertTengah(string data, int posisi)```, dan ```insertBelakang(string data)```. Fungsi ```hapusDepan()```, ```hapusBelakang()```, dan ```hapusTengah(int posisi)``` digunakan untuk menghapus node di depan, belakang, dan tengah SLLC. Fungsi ```clearList()``` digunakan untuk menghapus semua node dalam SLLC. Program ini juga memiliki fungsi ```tampil()``` untuk menampilkan isi SLLC. Dalam contoh program, SLLC digunakan untuk menampilkan daftar hewan, seperti ayam, bebek, cicak, domba, sapi, dan lain-lain. Program ini juga menunjukkan bagaimana melakukan operasi insert, delete, dan traversal pada SLLC.

## Unguided

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.
#### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa

```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = NULL; }
    void addNode(string nama, string nim);
    void addNodeAtPos(string nama, string nim, int pos);
    void updateNode(string nama, string nim, int pos);
    void deleteNode(int pos);
    void displayList();
    void deleteList();
};

void LinkedList::addNode(string nama, string nim) {
    Node* temp = new Node();
    temp->nama = nama;
    temp->nim = nim;
    temp->next = head;
    head = temp;
}

void LinkedList::addNodeAtPos(string nama, string nim, int pos) {
    Node* temp1 = new Node();
    Node* temp2 = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp2 != NULL) {
            temp2 = temp2->next;
        }
    }
    if (temp2 == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    temp1->nama = nama;
    temp1->nim = nim;
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void LinkedList::updateNode(string nama, string nim, int pos) {
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    temp->nama = nama;
    temp->nim = nim;
}

void LinkedList::deleteNode(int pos) {
    Node* temp1 = head;
    Node* temp2 = NULL;
    for (int i = 1; i < pos; i++) {
        if (temp1 != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }
    if (temp1 == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (temp2 == NULL) {
        head = temp1->next;
    }
    else {
        temp2->next = temp1->next;
    }
    delete temp1;
}

void LinkedList::displayList() {
    Node* temp = head;
    cout << endl << "==================================" << endl;
    cout << left << setw(15) << "Nama" << setw(15) << "NIM" << endl;
    cout << "==================================" << endl;
    while (temp != NULL) {
        cout << left << setw(15) << temp->nama << setw(15) << temp->nim << endl;
        temp = temp->next;
    }
    cout << "==================================\n" << endl;
}

void LinkedList::deleteList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
}

int main() {
    LinkedList list;
    int choice, position;
    string name, nim;
    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n" << endl;
        cout << "-------- Main Menu --------\n" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR\n" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Tambah Depan" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.addNode(name, nim);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            cout << "Tambah Belakang" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.addNodeAtPos(name, nim, 0);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            cout << "Tambah Tengah" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> position;
            list.addNodeAtPos(name, nim, position);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            cout << "Ubah Depan" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.updateNode(name, nim, 1);
            cout << "Data telah diubah" << endl;
            break;
        case 5:
            cout << "Ubah Belakang" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.updateNode(name, nim, 0);
            cout << "Data telah diubah" << endl;
            break;
        case 6:
            cout << "Ubah Tengah" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> position;
            list.updateNode(name, nim, position);
            cout << "Data telah diubah" << endl;
            break;
        case 7:
            cout << "Hapus Depan" << endl;
            list.deleteNode(1);
            cout << "Data telah dihapus" << endl;
            break;
        case 8:
            cout << "Hapus Belakang" << endl;
            list.deleteNode(0);
            cout << "Data telah dihapus" << endl;
            break;
        case 9:
            cout << "Hapus Tengah" << endl;
            cout << "Masukkan Posisi : ";
            cin >> position;
            list.deleteNode(position);
            cout << "Data telah dihapus" << endl;
            break;
        case 10:
            cout << "Hapus List" << endl;
            list.deleteList();
            cout << "Data telah dihapus" << endl;
            break;
        case 11:
            cout << "TAMPILKAN" << endl;
            list.displayList();
            break;
        case 0:
            cout << "KELUAR\n" << endl;
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid\n" << endl;
            break;
        }
    }
    return 0;
}
```
Kode di atas digunakan untuk mengelola daftar mahasiswa (berupa nama dan NIM) menggunakan struktur data Linked List Non-Circular. Mahasiswa disimpan dalam struktur data bernama ```Node``` yang memiliki field ```nama``` (string) dan ```nim``` (string). Beberapa fungsi disediakan untuk menambah data mahasiswa baru di depan, belakang, atau posisi tertentu, serta menghapus mahasiswa di depan, belakang, atau posisi tertentu. Fungsi ```updateNode``` memungkinkan perubahan data mahasiswa pada posisi tertentu. Fungsi ```displayList``` menampilkan daftar mahasiswa dengan format yang rapi, yaitu nama dan NIM mahasiswa. Program ini didesain secara interaktif, pengguna dapat memilih operasi yang diinginkan melalui menu yang disediakan. Jika pengguna sudah selesai memasukkan data mahasiswa, program akan menampilkan data tersebut. Program akan berhenti jika pengguna memilih menu KELUAR dengan menggunakan fungsi ```break```.

##### Output:
![Screenshot 2024-04-29 141735](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/a2b79113-15bc-458f-b1e9-0a50aafe7ccd)

#### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/b7a57459-9a68-4e92-9af5-c4fe0704df91)

##### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/60e2e086-8716-409a-8b5f-770692060b90)

#### 3. Lakukan perintah berikut: 
- Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004
- Hapus data Denis 
- Tambahkan data berikut di awal: Owi 2330000 
- Tambahkan data berikut di akhir: David 23300100 
- Ubah data Udin menjadi data berikut: Idin 23300045 
- Ubah data terkahir menjadi berikut: Lucy 23300101 
- Hapus data awal 
- Ubah data awal menjadi berikut: Bagas 2330002 
- Hapus data akhir 
- Tampilkan seluruh data

##### Output:
![Screenshot 2024-04-29 145033](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/313950ba-af77-4140-8544-01d596c9de15)

## Kesimpulan

Tipe data digunakan untuk mengklasifikasikan berbagai jenis data. Tiga jenis tipe data yang umum digunakan yaitu tipe data primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman, contohnya int, float, char, dan bool. Tipe data abstrak merupakan suatu tipe data buatan diri sendiri sesuai keinginan, yang dapat diimplementasikan menggunakan struct atau class. Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel, contohnya array, vector, dan map.

## Referensi
[1] M. P. Putri et al., Algoritma Dan Struktur Data. 2022.
[2] Warno, “Pembelajaran Pemrograman Bahasa Java Dan Arti Keyword,” Pembelajaran Pemrograman Bhs. Java Dan Arti Keyword, vol. 8, no. 1, pp. 40–51, 2020.
[3] D. Rosadi, “ADT (Abstract Data Type) C++,” medium.com. Accessed: Mar. 10, 2024. [Online]. Available: https://medium.com/@111202214191/adt-abstract-data-type-c-4cdcf4441d8c
[4] R. Muliono, “ABSTRACT DATA TYPE (ADT),” blog.uma.ac.id. Accessed: Mar. 10, 2024. [Online]. Available: https://rizkimuliono.blog.uma.ac.id/wp-content/uploads/sites/365/2017/05/ADT-Abstract-Data-Type.pdf
