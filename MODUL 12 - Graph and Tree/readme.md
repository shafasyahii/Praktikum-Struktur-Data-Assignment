# <h1 align="center">Laporan Praktikum Modul Priority Graph dan Tree</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

### Graph
Graph merupakan representasi dari suatu masalah yang digambarkan sebagai sekumpulan noktah atau simpul (vertex) yang dihubungkan dengan sekumpulan garis atau sisi (edge) [1]. Graf G didefisikan : pasangan himpunan (V, E) dengan notasi G = (V, E). Dalam hal ini, V adalah himpunan tidak kosong dari simpulsimpul (vertices atau node) dan E adalah himpunan sisi (edges atau arcs) yang menghubungkan sepasang simpul [2].  Secara geometri graf digambarkan sebagai sekumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi) [3]. 

![Screenshot 2024-06-10 144346](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/0915be4e-2417-4db3-bb13-4e27298d3ab8)

Ada beberapa cara untuk menyimpan graph di dalam sitem komputer. Struktur data bergantung pada struktur graph dan algoritma yang digunakan untuk memanipulasi graph. Secara teori salah satu dari keduanya dapat dibedakan antara struktur list dan matriks, tetapi dalam penggunaannya struktur terbaik yang sering digunakan adalah kombinasi keduanya.
1. Graph tak berarah (undirected graph atau non-directed graph)
- Urutan simpul dalam sebuah busur tidak dipentingkan. Misal busur e1 dapat disebut busur AB atau BA

2. Graph berarah (directed graph) 
- Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.

3. Graph Berbobot (Weighted Graph)
- Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 buah simpul, maka busur tersebut dinyatakan memiliki bobot.
- Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll.

Terdapat istilah – istilah yang berkaitan dengan graph, yaitu :
- Vertex : himpunan node/titik pada sebuah graph.
- Edge : garis yang menghubungkan tiap node/vertex.
- Adjacent : dua buah titik dikatakan berdekatan juka dua buah titik tersebut terhubung dengan sebuah sisi.
- Weight : Sebuah graph dikatakan berbobot apabila terdapat sebuah fungsi bobot bernilai real pada himpunan Edge.
- Path : walk dengan setiap vertex berbeda. Walk didefinisikan sebagai ururtan vertex dan edge. Diawali dengan origin vertex dan diakhiri dengan terminus vertex.
- Cycle : siklus atau sirkuit yang berawal dan berakhir pada simpul yang sama.

### Tree
Pohon ( tree) adalah graph terhubung yang tidak mengandung sirkuit. Pohon (tree) merupakan stuktur data yang tidak linier yang digambarkan dengan hubungan yang bersifat hirarkis antar satu elemen [4]. 

#### Sifat-sifat pohon
Misalkan G = (V, E) adalah graf takberarah sederhana dan jumlah simpulnya n. Maka, semua pernyataan di bawah ini adalah ekivalen [5]:
1. G adalah pohon.
2. Setiap pasang simpul di dalam G terhubung dengan lintasan tunggal.
3. G terhubung dan memiliki m = n – 1 buah sisi.
4. G tidak mengandung sirkuit dan memiliki m = n – 1 buah sisi.
5. G tidak mengandung sirkuit dan penambahan satu sisi pada graf akan membuat hanya satu sirkuit.
6. G terhubung dan semua sisinya adalah jembatan. 

#### Jenis-jenis pohon
Ada Beberapa Jenis TREE di antaranya :

1. BINARY TREE
Tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua sub pohon dan kedua subpohon harus terpisah.
Kelebihan struktur Binary Tree :
- Mudah dalam penyusunan algoritma sorting
- Searching data relatif cepat
- Fleksibel dalam penambahan dan penghapusan data

Dari Binary Tree ini, ada 2 tipe :
- Full Binary Tree : Semua node, kecuali leaf pasti memiliki 2 anak dan tiap subpohon memiliki panjang path yang sama.

![Screenshot 2024-06-10 145727](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/03e9e9c6-cdbd-4c86-ae7b-0ab0b6880695)

- Complete Binary Tree : Tree yang mirip dengan full binary tree, tapi tiap subtree boleh memiliki panjang path yang berbeda dan tiap node (kecuali leaf) memiliki 2 anak.

![Screenshot 2024-06-10 145737](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/8139b3a5-ebda-4c7d-bc62-8451c8234650)

2. SKEWED BINARY TREE
Binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu anak.

![Screenshot 2024-06-10 152330](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/6635e30f-b25e-4c82-bdc2-0242f77f2000)

#### Operasi
1. Create: membentuk sebuah tree baru yang kosong.
2. Insert: menambah node ke dalam Tree.
Jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan, sebaliknya jika lebih kecil maka akan diletakkan di node sebelah kiri. Untuk data pertama akan menjadi elemen root.
3. PreOrder: cetak node yang dikunjungi, kunjungi left, kunjungi right
4. InOrder: kunjungi left, cetak node yang dikunjungi, kunjungi right
5. PostOrder: kunjungi left, kunjungi right, cetak node yang dikunjungi

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
Kode di atas digunakan untuk menampilkan grafik yang menggambarkan koneksi antar kota di Jawa Barat dan Yogyakarta.

Berikut adalah penjelasan tentang kodingan tersebut:

1. ```#include <iostream>``` dan ```#include <iomanip>``` adalah direktif untuk mengincludekan library input/output dan manipulasi input/output ke dalam program.
2. ```using namespace std;``` adalah perintah untuk menggunakan namespace standar C++ yang berisi fungsi-fungsi dan variabel-variabel yang umum digunakan.
3. ```string simpul[7] = {...};``` adalah deklarasi array of string yang berisi nama-nama kota, yaitu Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, dan Yogyakarta.
4. ```int busur[7][7] = {...};``` adalah deklarasi array of integer yang berisi bobot koneksi antar kota. Nilai 0 berarti tidak ada koneksi antar kota, sedangkan nilai lainnya berarti ada koneksi dengan bobot tertentu.
5. Fungsi ```tampilanGraph()``` digunakan untuk menampilkan grafik yang menggambarkan koneksi antar kota. Fungsi ini menggunakan loop untuk mengiterasi array ```simpul``` dan ```busur```, dan menampilkan nama kota serta bobot koneksi antar kota yang terkait.
6. Fungsi ```main()``` adalah fungsi utama program yang memanggil fungsi ```tampilanGraph()``` untuk menampilkan grafik.

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
Kode di atas digunakan untuk mengimplementasikan struktur data tree (pohon) serta melakukan traversal (pengulangan) pada pohon tersebut menggunakan tiga metode: pre-order, in-order, dan post-order.

Berikut adalah penjelasan tentang kodingan tersebut:

1. ```struct TNode``` adalah definisi struktur data untuk node pada pohon. Setiap node memiliki tiga komponen: ```data``` untuk menyimpan nilai integer, ```left``` untuk menyimpan pointer ke node anak kiri, dan ```right``` untuk menyimpan pointer ke node anak kanan.
2. Konstruktor ```TNode(int value)``` digunakan untuk membuat node baru dengan nilai ```value``` dan menginisialisasi pointer ```left``` dan ```right``` ke ```NULL```.
3. Fungsi ```preOrder(TNode *node)``` digunakan untuk melakukan traversal pre-order pada pohon. Fungsi ini akan mencetak nilai node saat ini, kemudian melakukan rekursi pada node anak kiri dan kanan.
4. Fungsi ```inOrder(TNode *node)``` digunakan untuk melakukan traversal in-order pada pohon. Fungsi ini akan melakukan rekursi pada node anak kiri, mencetak nilai node saat ini, kemudian melakukan rekursi pada node anak kanan.
5. Fungsi ```postOrder(TNode *node)``` digunakan untuk melakukan traversal post-order pada pohon. Fungsi ini akan melakukan rekursi pada node anak kiri dan kanan, kemudian mencetak nilai node saat ini.
6. Pada fungsi ```main()```, kita membuat node-node baru dan menghubungkannya untuk membentuk pohon seperti berikut:
```C++
      7
     / \
    1   9
   / \ / \
  0  5 8
```
7. Kemudian, kita melakukan traversal pada pohon menggunakan tiga metode: pre-order, in-order, dan post-order.

Penjelasan output:

- Pre-order: kita mencetak nilai node saat ini, kemudian melakukan rekursi pada node anak kiri dan kanan. Hasilnya adalah urutan node yang dikunjungi dalam traversal pre-order.
- In-order: kita melakukan rekursi pada node anak kiri, mencetak nilai node saat ini, kemudian melakukan rekursi pada node anak kanan. Hasilnya adalah urutan node yang dikunjungi dalam traversal in-order.
- Post-order: kita melakukan rekursi pada node anak kiri dan kanan, kemudian mencetak nilai node saat ini. Hasilnya adalah urutan node yang dikunjungi dalam traversal post-order.

## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Deklarasi fungsi untuk menampilkan matriks jarak
void printMatrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

// Fungsi utama
int main() {
  // Deklarasi variabel untuk NIM
  int nim = 22102003;

  // Deklarasi variabel untuk jumlah simpul
  int numVertices;
  cout << "Silakan masukkan jumlah simpul: ";
  cin >> numVertices;

  // Deklarasi variabel untuk menyimpan nama simpul
  vector<string> nodes(numVertices);
  for (int i = 0; i < numVertices; i++) {
    cout << "Silakan masukkan nama simpul " << i + 1 << ": ";
    cin >> nodes[i];
  }

  // Deklarasi dan inisialisasi matriks jarak
  vector<vector<int>> distanceMatrix(numVertices, vector<int>(numVertices, 0));

  // Meminta inputan bobot antar simpul
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      cout << "Masukkan bobot " << nodes[i] << " ke " << nodes[j] << ": ";
      cin >> distanceMatrix[i][j];
    }
  }

  // Menampilkan matriks jarak
  cout << endl;
  cout << "Matriks Jarak:" << endl;
  printMatrix(distanceMatrix);

  // Algoritma Dijkstra untuk menghitung jarak dari simpul awal ke semua simpul lain
  int startNode;
  cout << endl;
  cout << "Masukkan simpul awal: ";
  cin >> startNode;

  // Memastikan simpul awal valid
  if (startNode < 0 || startNode >= numVertices) {
    cout << "Simpul awal tidak valid." << endl;
    return 1;
  }

  // Deklarasi variabel untuk menyimpan jarak terpendek ke setiap simpul
  vector<int> shortestDistances(numVertices, INT_MAX);
  shortestDistances[startNode] = 0;

  // Inisialisasi visited array (ukuran sama dengan jumlah simpul, default false)
  vector<bool> visited(numVertices, false);

  // Algoritma Dijkstra
  for (int i = 0; i < numVertices; i++) {
    // Menemukan simpul dengan jarak terpendek saat ini
    int currentVertex = -1;
    int minDistance = INT_MAX;
    for (int j = 0; j < numVertices; j++) {
      if (shortestDistances[j] < minDistance && visited[j] == false) {
        currentVertex = j;
        minDistance = shortestDistances[j];
      }
    }

    // Menandai simpul saat ini sebagai telah dikunjungi
    if (currentVertex != -1) {
      visited[currentVertex] = true;

      // Memperbarui jarak terpendek ke simpul lain
      for (int j = 0; j < numVertices; j++) {
        if (distanceMatrix[currentVertex][j] != 0 && shortestDistances[j] > shortestDistances[currentVertex] + distanceMatrix[currentVertex][j]) {
          shortestDistances[j] = shortestDistances[currentVertex] + distanceMatrix[currentVertex][j];
        }
      }
    }
  }

  // Menampilkan jarak terpendek ke setiap simpul
  cout << endl;
  cout << "Jarak terpendek dari " << nodes[startNode] << " ke simpul lain:" << endl;
  for (int i = 0; i < numVertices; i++) {
    cout << nodes[i] << ": " << shortestDistances[i] << endl;
  }

  return 0;
}
```
#### Output:
![Screenshot 2024-06-10 152531](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/1a1435fa-9fde-4e2a-a4af-8eda3f8e28cc)

Kode di atas digunakan untuk mengimplementasikan algoritma Dijkstra untuk menghitung jarak terpendek antar simpul dalam sebuah grafik. Algoritma Dijkstra digunakan untuk menghitung jarak terpendek dari simpul awal ke semua simpul lain. Matriks jarak berisi bobot antar simpul yang digunakan untuk menghitung jarak terpendek. Kodingan ini meminta inputan jumlah simpul, nama simpul, bobot antar simpul, dan simpul awal dari pengguna. Hasil output dari kodingan ini adalah jarak terpendek dari simpul awal ke setiap simpul lain.

### 2.	Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
#include<iostream>
#include<queue>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // Constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Fungsi untuk menambahkan node ke tree
TNode* tambahNode(TNode* root, int data) {
    if (root == NULL) {
        return new TNode(data);
    }
    queue<TNode*> q;
    q.push(root);

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new TNode(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new TNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

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

// Fungsi untuk menampilkan child dari node yang diinput
void tampilChild(TNode* node, int value) {
    if (node == NULL) return;
    if (node->data == value) {
        if (node->left != NULL) {
            cout << "Left Child: " << node->left->data << endl;
        } else {
            cout << "Left Child: NULL" << endl;
        }
        if (node->right != NULL) {
            cout << "Right Child: " << node->right->data << endl;
        } else {
            cout << "Right Child: NULL" << endl;
        }
        return;
    }
    tampilChild(node->left, value);
    tampilChild(node->right, value);
}

// Fungsi untuk menampilkan semua descendant dari node yang diinput
void tampilDescendant(TNode* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    tampilDescendant(node->left);
    tampilDescendant(node->right);
}

int main() {
    TNode* root = NULL;
    int pilihan, data, nodeValue;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Node\n";
        cout << "2. Tampilkan Pre-Order\n";
        cout << "3. Tampilkan In-Order\n";
        cout << "4. Tampilkan Post-Order\n";
        cout << "5. Tampilkan Child dari Node\n";
        cout << "6. Tampilkan Descendant dari Node\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                root = tambahNode(root, data);
                break;
            case 2:
                cout << "Pre-Order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-Order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-Order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Masukkan nilai node: ";
                cin >> nodeValue;
                tampilChild(root, nodeValue);
                break;
            case 6:
                cout << "Masukkan nilai node: ";
                cin >> nodeValue;
                cout << "Descendant dari " << nodeValue << ": ";
                tampilChild(root, nodeValue);
                tampilDescendant(root);
                cout << endl;
                break;
            case 7:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-06-10 140711](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/b092db89-dbe7-433d-b176-0c3358132f06)
![Screenshot 2024-06-10 140720](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/8d56d75b-2d22-4a88-88a1-29d6101dc95e)
![Screenshot 2024-06-10 140729](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/8e8c203a-8cea-44de-8cc2-50a602e020bb)

Kode di atas digunakan untuk mengimplementasikan struktur data tree (pohon) serta melakukan beberapa operasi pada pohon tersebut.

Berikut adalah penjelasan tentang kodingan tersebut:

1. Struktur data ```TNode``` digunakan untuk merepresentasikan node pada pohon. Setiap node memiliki tiga komponen: ```data``` untuk menyimpan nilai integer, ```left``` untuk menyimpan pointer ke node anak kiri, dan ```right``` untuk menyimpan pointer ke node anak kanan.
2. Fungsi ```tambahNode``` digunakan untuk menambahkan node baru ke pohon. Fungsi ini menggunakan queue untuk melakukan traversal pada pohon dan menemukan node yang kosong untuk menambahkan node baru.
3. Fungsi ```preOrder```, ```inOrder```, dan ```postOrder``` digunakan untuk melakukan traversal pada pohon menggunakan metode pre-order, in-order, dan post-order.
4. Fungsi ```tampilChild``` digunakan untuk menampilkan child dari node yang diinput. Fungsi ini melakukan traversal pada pohon dan menemukan node yang sesuai dengan nilai yang diinput, kemudian menampilkan child dari node tersebut.
5. Fungsi ```tampilDescendant``` digunakan untuk menampilkan semua descendant dari node yang diinput. Fungsi ini melakukan traversal pada pohon dan menemukan node yang sesuai dengan nilai yang diinput, kemudian menampilkan semua descendant dari node tersebut.
6. Pada fungsi ```main()```, kita membuat menu untuk memilih operasi yang ingin dilakukan pada pohon. Operasi yang tersedia adalah:
- Tambah node baru ke pohon
- Tampilkan pre-order, in-order, dan post-order
- Tampilkan child dari node yang diinput
- Tampilkan descendant dari node yang diinput
- Keluar dari program


## Kesimpulan

Graph dan tree adalah dua struktur data yang penting dengan aplikasi yang luas. Graph digunakan untuk menggambarkan hubungan antar elemen yang kompleks, sedangkan tree digunakan untuk merepresentasikan hierarki. Memahami perbedaan dan persamaan antara keduanya dapat membantu memilih struktur data yang tepat untuk suatu masalah.

## Referensi
[1] I. Afrianto, “Penyelesaian Masalah Minimum Spanning Tree (Mst) Menggunakan Ant Colony System (Acs),” *Komputa  J. Ilm. Komput.* dan Inform., vol. 1, no. 2, 2012, doi: 10.34010/komputa.v1i2.59.

[2] T. Nudiyanto and E. Susanti, “Efisiensi Penggunaan Matriks In-Degree Untuk Mengkontruksi Spanning-Tree pada Graf Berarah,” *J. Edukasi dan Sains Mat.*, vol. 5, no. 1, pp. 1–15, 2019.

[3] S. Rizki, “Penerapan Teori Graf Untuk Menyelesaikan Masalah Minimum Spanning Tree (Mst) Menggunakan Algoritma Kruskal,” *AKSIOMA J. Math. Educ.,* vol. 1, no. 2, 2012, doi: 10.24127/ajpm.v1i2.68.

[4] F. Latifah, “PENYIMPANAN DATA DALAM TEKNIK PEMROGRAMAN ( kajian algorithma pohon pada teknik pemrograman ),” vol. XIII, no. 2, pp. 23–32, 2016, [Online]. Available: http://ejournal.nusamandiri.ac.id/ejurnal/index.php/techno/article/view/357/287

[5] A. Muntaha, “Graf Pohon dan Implementasinya dalam beberapa persoalan,” p. 11, 2020.
