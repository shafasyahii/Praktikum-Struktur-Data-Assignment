#include <iostream>
#include <string>

using namespace std;

// Create a structure named 'buku' with arrays of size 5
struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

int main() {
    // Initialize and fill the 'buku' structure
    buku myBook;
    myBook.judul_buku[0] = "The Catcher in the Rye";
    myBook.judul_buku[1] = "Catch-22";
    myBook.judul_buku[2] = "To Kill a Mockingbird";
    myBook.judul_buku[3] = "1984";
    myBook.judul_buku[4] = "Brave New World";

    myBook.pengarang[0] = "J.D. Salinger";
    myBook.pengarang[1] = "Joseph Heller";
    myBook.pengarang[2] = "Harper Lee";
    myBook.pengarang[3] = "George Orwell";
    myBook.pengarang[4] = "Aldous Huxley";

    myBook.penerbit[0] = "Little, Brown and Company";
    myBook.penerbit[1] = "Simon & Schuster";
    myBook.penerbit[2] = "Harper & Row";
    myBook.penerbit[3] = "Secker and Warburg";
    myBook.penerbit[4] = "Chatto & Windus";

    myBook.tebal_halaman[0] = 277;
    myBook.tebal_halaman[1] = 453;
    myBook.tebal_halaman[2] = 281;
    myBook.tebal_halaman[3] = 328;
    myBook.tebal_halaman[4] = 199;

    myBook.harga_buku[0] = 9.99;
    myBook.harga_buku[1] = 12.99;
    myBook.harga_buku[2] = 7.99;
    myBook.harga_buku[3] = 10.99;
    myBook.harga_buku[4] = 8.99;

    // Display the content of the 'buku' structure
    for (int i = 0; i < 5; i++) {
        cout << "Book Title: " << myBook.judul_buku[i] << endl;
        cout << "Author: " << myBook.pengarang[i] << endl;
        cout << "Publisher: " << myBook.penerbit[i] << endl;
        cout << "Page Thickness: " << myBook.tebal_halaman[i] << endl;
        cout << "Book Price: $" << myBook.harga_buku[i] << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}