# <h1 align="center">Laporan Praktikum Modul Priority Graph dan Tree</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori


## Guided 

### Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0,7,8,0,0,0,0},
    {0,0,5,0,0,15,0},
    {0,6,0,0,5,0,0},
    {0,5,0,0,2,4,0},
    {23,0,0,10,0,0,8},
    {0,0,0,0,7,0,3},
    {0,0,0,0,9,4,0}
};

void tampilanGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilanGraph();
    return 0;
}
```
Kode di atas digunakan untuk 

### Program Tree

```C++
#include<iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder (node -> left);
        cout << node -> data << " ";
        inOrder(node -> right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven -> left = one;
    // 7
    // /\
    // 1 NULL

    seven -> right = nine;
    // 7
    // /\
    // 1 9

    one -> left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one -> right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine -> left = eight;
    // 7
    // /\
    // 1 9
    // / \ / \
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}
```

## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++

```
#### Output:
![Screenshot 2024-05-20 112359](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/72328a37-52f4-4d41-8896-f316a1f01025)

Modifikasi yang dilakukan adalah:
1. Menambahkan input untuk jumlah elemen yang akan diinputkan dan elemen-elemen tersebut secara manual.
2. Menambahkan input untuk indeks elemen yang akan diubah prioritas dan prioritas baru.
3. Menambahkan input untuk indeks elemen yang akan dihapus.
4. Menambahkan validasi untuk indeks elemen yang tidak valid.
5. Menambahkan pesan error untuk situasi-situasi yang tidak valid seperti heap yang kosong atau indeks elemen yang tidak valid.

## Kesimpulan

Priority Queue adalah konsep penting dalam algoritma yang membantu kita mengelola dan mengatur data dengan nilai prioritas tertentu. Implementasinya dalam struktur data seperti heap atau binary search tree memungkinkan operasi penyisipan dan penghapusan elemen dalam waktu logaritmik, yang sangat berguna dalam berbagai algoritma. Dengan pemahaman tentang Priority Queue, kita dapat meningkatkan efisiensi dan efektivitas algoritma yang kita gunakan dalam menyelesaikan masalah. Kemudian pohon heap adalah struktur data yang berbentuk pohon yang memenuhi sifat-sifat heap yaitu jika B adalah anak dari A, maka nilai yang tersimpan di simpul A lebih besar atau sama dengan nilai yang tersimpan di simpul B.

## Referensi
[1] A. Nurcholis, S. Batara N, and M. Octamanullah, “Penerapan struktur data Heap Priority Queue pada algoritma Djikstra untuk mendapatkan kompleksitas O((n + m)log n),” pp. 1–4, 2020.

[2] F. Mulia, “Penerapan Pohon Dalam Heap Sort”.

[3] A. Sindar, Struktur Data Dan Algoritma, no. December. 2018.
