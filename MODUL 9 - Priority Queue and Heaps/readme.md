# <h1 align="center">Laporan Praktikum Modul Priority Queue and Heaps</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Priority Queue

Priority Queue adalah suatu bentuk struktur data yang berbasiskan struktur Queue pada umumnya. Pada priority Queue, terdapat salah satu bentuk implementasi yaitu implementasi menggunakan struktur data heaps. Dalam implementasi ini ada 3 pokok atribut yaitu heaps, comparator, dan last. Dengan menggunakan fasilitas heap ini kita bisa melakukan insert atau remove elemen dalam kompleksitas waktu logaritmik. Pada priority Queue ini, secara keseluruhan akan dibentuk sebuah pohon biner yang seimbang. Dalam pembuatan pohon biner ini diusahakan ketinggian yang terbentuk adalah minimum. Keminimuman tinggi pohon inilah yang menyebabkan kompleksitas waktu dalam memanipulasi daun menjadi fungsi logaritmik [Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n) ].

Struktur Priority Queue :
[foto]
Heap menunjuk pada akar, last menunjuk pada elemen akhir, dan comparator menunjukan pembanding untuk menipulasi posisi [Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n) ].

#### Heaps

Pohon heap adalah struktur data yang berbentuk pohon yang memenuhi sifat-sifat heap yaitu jika B adalah anak dari A, maka nilai yang tersimpan di simpul A lebih besar atau sama dengan nilai yang tersimpan di simpul B. Hal ini mengakibatkan elemen dengan nilai terbesar selalu berada pada posisi akar, dan heap ini disebut max heap. (Bila perbandingannya diterbalikkan yaitu elemen terkecilnya selalu berada di simpul akar, heap ini disebut adalah min heap). Karena itulah, heap biasa dipakai untuk mengimplementasikan priority queue. Operasi-operasi yang digunakan untuk heap adalah [Penerapan Pohon Dalam Heap Sort] :
- Delete-max atau delete-min: menghapus simpul akar dari sebuah max- atau min-heap.
- Increase-key atau decrease-key: mengubah nilai yang tersimpan di suatu simpul.
- Insert: menambahkan sebuah nilai ke dalam heap.
- Merge: menggabungkan dua heap untuk membentuk sebuah heap baru yang berisi semua elemen pembentuk heap tersebut.

Jenis-jenis heap:


## Guided 

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan struktur data yang disebut antrian prioritas (priority queue). Antrian prioritas adalah struktur data yang mirip dengan antrian biasa, namun elemen yang ditambahkan memiliki prioritas. Elemen dengan prioritas lebih tinggi akan dikeluarkan terlebih dahulu dari antrian. Kode ini menggunakan representasi min-heap untuk antrian prioritas. Min-heap adalah pohon di mana setiap node (simpul) memiliki nilai yang lebih kecil atau sama dengan nilai anak-anaknya.

Berikut penjelasan fungsi-fungsi penting dalam kode tersebut:

- ```insert(p)```: Fungsi ini menambahkan elemen baru dengan nilai p ke dalam antrian prioritas.
- ```extractMax()```: Fungsi ini mengeluarkan elemen dengan prioritas tertinggi (nilai terkecil pada min-heap) dari antrian.
- ```changePriority(i, p)```: Fungsi ini mengubah prioritas dari elemen pada indeks ke-i menjadi nilai p.
- ```getMax()```: Fungsi ini mengembalikan nilai elemen dengan prioritas tertinggi (nilai terkecil pada min-heap) tanpa mengeluarkannya dari antrian.
- ```remove(i)```: Fungsi ini menghapus elemen pada indeks ke-i dari antrian.

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
![image](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/d5c8b1c3-93b7-4f74-85c9-1b3f1ff77d22)

Modifikasi yang dilakukan adalah:
1. Menambahkan input untuk jumlah elemen yang akan diinputkan dan elemen-elemen tersebut secara manual.
2. Menambahkan input untuk indeks elemen yang akan diubah prioritas dan prioritas baru.
3. Menambahkan input untuk indeks elemen yang akan dihapus.
4. Menambahkan validasi untuk indeks elemen yang tidak valid.
5. Menambahkan pesan error untuk situasi-situasi yang tidak valid seperti heap yang kosong atau indeks elemen yang tidak valid.

## Kesimpulan

Tipe data digunakan untuk mengklasifikasikan berbagai jenis data. Tiga jenis tipe data yang umum digunakan yaitu tipe data primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang disediakan oleh banyak bahasa pemrograman, contohnya int, float, char, dan bool. Tipe data abstrak merupakan suatu tipe data buatan diri sendiri sesuai keinginan, yang dapat diimplementasikan menggunakan struct atau class. Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan dan mengelola kumpulan data sekaligus dalam satu variabel, contohnya array, vector, dan map.

## Referensi
[1] N. Adlaimi, “SRUKTUR DATA MAJEMUK (QUEUE),” ResearchGate, 2019, doi: 10.31219/osf.io/cs53p.

[2] J. Sihombing, “Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java,” J. Ilm. Infokom, vol. 7, no. 2, pp. 15–24, 2019.

[3] A. Sindar, Struktur Data Dan Algoritma, no. December. 2018.