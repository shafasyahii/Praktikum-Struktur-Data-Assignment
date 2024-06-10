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