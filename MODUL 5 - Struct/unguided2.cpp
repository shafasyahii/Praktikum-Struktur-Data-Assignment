#include <iostream>
#include <string>

using namespace std;

int main() {
    // Deklarasi array
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];

    // Mengisi data
    judul_buku[0] = "The Catcher in the Rye";
    judul_buku[1] = "Catch-22";
    judul_buku[2] = "To Kill a Mockingbird";
    judul_buku[3] = "1984";
    judul_buku[4] = "Brave New World";

    pengarang[0] = "J.D. Salinger";
    pengarang[1] = "Joseph Heller";
    pengarang[2] = "Harper Lee";
    pengarang[3] = "George Orwell";
    pengarang[4] = "Aldous Huxley";

    penerbit[0] = "Little, Brown and Company";
    penerbit[1] = "Simon & Schuster";
    penerbit[2] = "Harper & Row";
    penerbit[3] = "Secker and Warburg";
    penerbit[4] = "Chatto & Windus";

    tebal_halaman[0] = 277;
    tebal_halaman[1] = 453;
    tebal_halaman[2] = 281;
    tebal_halaman[3] = 328;
    tebal_halaman[4] = 199;

    harga_buku[0] = 9.99;
    harga_buku[1] = 12.99;
    harga_buku[2] = 7.99;
    harga_buku[3] = 10.99;
    harga_buku[4] = 8.99;

    // Menampilkan data (mirip dengan kode sebelumnya)
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku Favorit Saya" << endl;
        cout << "\tJudul Buku : " << judul_buku[i] << endl;
        cout << "\tPengarang : " << pengarang[i] << endl;
        cout << "\tPenerbit : " << penerbit[i] << endl;
        cout << "\tTebal Halaman: " << tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << harga_buku[i] << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}