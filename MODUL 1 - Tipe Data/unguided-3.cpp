#include <iostream>
#include <map>

// Main program
int main() {
    // Membuat map dengan tipe string sebagai key dan tipe integer sebagai value
    std::map<std::string, int> mapNamaNilai;

    // Menambahkan data ke dalam map
    mapNamaNilai.insert(std::make_pair("Susi", 25));
    mapNamaNilai.insert(std::make_pair("Budi", 30));
    mapNamaNilai.insert(std::make_pair("Agung", 35));

    // Mencetak semua data pada map
    for (const auto& item : mapNamaNilai) {
        std::cout << "Nama: " << item.first << ", Nilai: " << item.second << std::endl;
    }

    // Mengubah nilai dari key "Susi"
    mapNamaNilai["Susi"] = 26;

    // Menambahkan data baru ke dalam map
    mapNamaNilai["Dewi"] = 40;

    // Menghapus data dari key "Budi"
    mapNamaNilai.erase("Budi");

    // Mencetak semua data pada map setelah diubah
    std::cout << std::endl;
    for (const auto& item : mapNamaNilai) {
        std::cout << "Nama: " << item.first << ", Nilai: " << item.second << std::endl;
    }

    return 0;
}