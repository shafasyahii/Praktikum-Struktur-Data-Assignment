# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Queue (antrian) adalah salah satu list linier dari struktur data yang beroperasi dengan cara First In First Out (FIFO) yaitu elemen pertama yang masuk merupakan elemen yang pertama keluar. Data-data di dalam antrian dapat bertipe integer, real, record dalam bentuk sederhana atau terstruktur. Queue dilakukan dengan cara penyisipan di satu ujung, sedang penghapusan di ujung lain. Ujung penyisipan biasa disebut rear/tail, sedang ujung penghapusa disebut front/head [1]. 

Sebuah queue dalam program setidaknya harus mengandung tiga variabel, yakni: head untuk penanda bagian depan antrian, tail untuk penanda bagian belakang antrian, dan array data untuk menyimpan data-data yang dimasukkan ke dalam queue tersebut [1]. 

Queue dapat dideklarasikan dengan bentuk seperti berikut [2]:

```C++
define maxsize 100
typdef struct {
int jumlah; //jumlah data
int depan; //ujung depan
int belakang; //ujung belakang
char data [ maxsize ]; //array isi queue
} queue;
```

QUEUE merupakan struktur data dinamis, ketika program dijalankan, jumlah elemennya dapat berubah secara dinamis sesuai keperluan Berikut ini operasi-operasi standar pada queue [3]:

1. Inisialisasi, merupakan prosedur untuk membuat queue pada kondisi awal, yaitu queue yang masih kosong (belum mempunyai elemen).
2. InQueue, Insert Queue merupakan prosedur untuk memasukkan sebuah elemen baru pada queue. Jumlah elemen Queue akan bertambah satu dan elemen tersebut merupakan elemen belakang.
3. DeQueue, Delete Queue merupakan prosedur untuk menghapus/mengambil sebuah elemen dari queue. Elemen yang diambil adalah elemen depan dan jumlah elemen queue akan berkurang satu.

Operasi-operasi yang berhubungan dengan jumlah elemen suatu queue adalah [3]:
1. Size, yaitu operasi untuk mendapatkan banyaknya elemen queue.
2. Empty, yaitu prosedur untuk mengetahui apakah queue dalam keadaan kosong atau tidak. Dengan status ini maka dapat dicegah dilakukannya operasi Dequeue dari suatu queue yang kosong.
3. Full, merupakan prosedur untuk mengetahui apakah Queue penuh atau tidak. Prosedur ini hanya berlaku untuk queue yang jumlahnya terbatas. 

## Guided 

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Kode ini digunakan untuk membuat simulasi antrian teller bank. Kode ini menggunakan array of string untuk menyimpan data antrian, dan beberapa fungsi untuk melakukan operasi pada antrian tersebut.

Berikut adalah fungsi-fungsi yang terdapat pada kode tersebut:

- ```isFull()```: Fungsi ini digunakan untuk mengecek apakah antrian sudah penuh.
- ```isEmpty()```: Fungsi ini digunakan untuk mengecek apakah antrian masih kosong.
- ```enqueueAntrian(string data)```: Fungsi ini digunakan untuk menambahkan data (nama nasabah) ke dalam antrian.
- ```dequeueAntrian()```: Fungsi ini digunakan untuk mengeluarkan data (nama nasabah) dari antrian.
- ```countQueue()```: Fungsi ini digunakan untuk menghitung jumlah data yang ada di dalam antrian.
- ```clearQueue()```: Fungsi ini digunakan untuk menghapus semua data yang ada di dalam antrian.
- ```viewQueue()```: Fungsi ini digunakan untuk menampilkan data yang ada di dalam antrian.

Pada fungsi main(), program terlebih dahulu menambahkan dua nama nasabah, yaitu "Andi" dan "Maya", ke dalam antrian. Kemudian, program menampilkan isi antrian dan jumlah antrian. Setelah itu, program mengeluarkan satu data dari antrian, lalu menampilkan kembali isi antrian dan jumlah antrian. Terakhir, program menghapus semua data yang ada di dalam antrian, dan kemudian menampilkan kembali isi antrian dan jumlah antrian.

## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>

using namespace std;

// Node structure for linked list implementation
struct Node {
    string data;
    Node* next;
};

class Queue {
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    void clearQueue() {
        Node* current = front;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        front = rear = nullptr;
    }

    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;

        for (int i = 1; i <= 5; i++) {
            if (current != nullptr) {
                cout << i << ". " << current->data << endl;
                current = current->next;
            } else {
                cout << i << ". (kosong)" << endl;
            }
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue queueTeller;

    queueTeller.enqueue("Andi");
    queueTeller.enqueue("Maya");
    queueTeller.enqueue("Rina");
    queueTeller.enqueue("Budi");
    queueTeller.enqueue("Doni");
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.dequeue();
    queueTeller.dequeue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.clearQueue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/f78c1f22-82cc-4f06-a342-0718bba9bccf)

Konsep Class Queue diterapkan dalam kode ini, di mana sebuah kelas dibuat untuk mewakili struktur data queue. Kelas Queue termasuk metode untuk berbagai operasi pada queue, seperti enqueue, dequeue, isEmpty, countQueue, clearQueue, dan viewQueue. Kelas Queue memiliki variabel front dan rear yang digunakan untuk menunjuk ke node pertama (front) dan node terakhir (rear) dalam queue. Variabel front dan rear diinisialisasi dalam konstruktor Queue().

Metode enqueue, dequeue, countQueue, clearQueue, dan viewQueue sekarang menjadi bagian dari kelas Queue, membuat kode lebih terstruktur dan modular. Akses ke variabel front dan rear dilakukan menggunakan operator titik pada objek Queue. Cara ini menawarkan beberapa keuntungan, termasuk pengertian dan pengelolaan operasi queue yang lebih mudah, serta kemampuan untuk menggunakan kembali kelas Queue dalam program lain yang memerlukan implementasi queue.

Perbedaan utama antara kode ini dengan versi sebelumnya adalah bahwa struktur Node sekarang didefinisikan dalam kelas Queue, serta variabel front dan rear sekarang menjadi variabel anggota kelas daripada variabel global. Selain itu, fungsi viewQueue masih menampilkan maksimal 5 elemen, namun queue sendiri tidak memiliki batasan ukuran karena implementasinya menggunakan linked list.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
#include <string>

using namespace std;

// Node structure for linked list implementation
struct Node {
    string NamaMahasiswa;
    string NIMMahasiswa;
    Node* next;
};

class Queue {
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string NamaMahasiswa, string NIMMahasiswa) {
        Node* newNode = new Node();
        newNode->NamaMahasiswa = NamaMahasiswa;
        newNode->NIMMahasiswa = NIMMahasiswa;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    void clearQueue() {
        Node* current = front;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        front = rear = nullptr;
    }

    void viewQueue() {
        cout << "Data antrian teller: " << endl;
        Node* current = front;

        for (int i = 1; i <= 5; i++) {
            if (current != nullptr) {
                cout << i << ". Nama: " << current->NamaMahasiswa << ", NIM: " << current->NIMMahasiswa << endl;
                current = current->next;
            } else {
                cout << i << ". (kosong)" << endl;
            }
        }
    }

private:
    Node* front;
    Node* rear;
};

int main() {
    Queue queueTeller;

    queueTeller.enqueue("Andi", "12345678");
    queueTeller.enqueue("Maya", "23456789");
    queueTeller.enqueue("Rina", "34567890");
    queueTeller.enqueue("Budi", "45678901");
    queueTeller.enqueue("Doni", "56789012");
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.dequeue();
    queueTeller.dequeue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;
    queueTeller.clearQueue();
    queueTeller.viewQueue();
    cout << "Jumlah antrian = " << queueTeller.countQueue() << endl;

    return 0;
}
```
#### Output:
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/ad2162fa-6467-4a32-b0e4-9a1b0cf3b518)

Kode ini masih menggunakan konsep class Queue untuk mengimplementasikan antrian, namun dengan perubahan pada struktur data yang disimpan dalam queue. Sebelumnya, class Queue menyimpan data berupa string generik. Pada kode ini, class Queue menyimpan data mahasiswa yang terdiri dari nama dan NIM mahasiswa. Untuk itu, struktur data Node dimodifikasi untuk memiliki atribut NamaMahasiswa dan NIMMahasiswa bertipe string. Fungsi-fungsi enqueue dan viewQueue juga dimodifikasi untuk bekerja dengan data mahasiswa tersebut. Antrian sekarang dapat menyimpan informasi yang lebih lengkap tentang mahasiswa yang mengantri. Fungsi viewQueue menampilkan nama dan NIM mahasiswa pada setiap node dalam antrian. Konsep class Queue dan fungsinya secara keseluruhan tetap sama. Class Queue masih menggunakan linked list untuk implementasi queue, sehingga tidak memiliki batasan ukuran maksimum.

## Kesimpulan

Queue (Antrian) adalah struktur data linier yang mengikuti aturan First In First Out (FIFO), di mana elemen pertama yang masuk akan menjadi elemen pertama yang keluar. Queue sering digunakan untuk simulasi antrian dalam kehidupan nyata, seperti antrean di kasir, antrean cetak dokumen, dan lain sebagainya. Queue dapat diimplementasikan menggunakan array atau linked list. Pada implementasi menggunakan array, perlu diperhatikan alokasi memori yang dinamis agar queue dapat menampung elemen sesuai kebutuhan.

## Referensi
[1] N. Adlaimi, “SRUKTUR DATA MAJEMUK (QUEUE),” ResearchGate, 2019, doi: 10.31219/osf.io/cs53p.

[2] J. Sihombing, “Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java,” J. Ilm. Infokom, vol. 7, no. 2, pp. 15–24, 2019.

[3] A. Sindar, Struktur Data Dan Algoritma, no. December. 2018.
