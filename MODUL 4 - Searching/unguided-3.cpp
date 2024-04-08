#include <iostream>

using namespace std;

// Fungsi Sequential Search
int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks pertama kali ditemukan
        }
    }
    return -1; // Jika tidak ditemukan, mengembalikan -1
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int target = 4;

    int result = sequentialSearch(data, n, target);

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}\n" << endl;

    if (result != -1) {
        cout << "Angka " << target << " ditemukan pada indeks: " << result << endl;
    } else {
        cout << "Angka " << target << " tidak ditemukan dalam data." << endl;
    }

    return 0;
}