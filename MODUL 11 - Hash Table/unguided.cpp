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