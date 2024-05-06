# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Shafa Syahida</p>

## Dasar Teori

Stack atau tumpukan adalah suatu stuktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO (Last In First Out) dimana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa di akses. Salah satu kelebihan stack adalah bahwa struktur data tersebut dapat di implementasikan baik pada array maupun pada linked list [1]. Misalkan sebuah kotak ditumpukkan, seperti pada gambar dibawah. Kotak A diletakkan pertama sekali kemudian diikuti secara berturut-turut kotak B, kotak C, kotak D, kotak E, dan terakhir kotak F. Maka untuk mengambil  tiap  kotak  dari  tumpukan  harus  dilakukan  secara berturut-turut mulai dari kotak F, kotak E, kotak D, kotak C, kotak B, kemudian kotak A. Karena jika kita membutuhkan kotak C misalnya dan langsung mengambil kotak C tanpa terlebih dahulu mengambil kotak di atasnya maka tumpukan akan tumbang.
![Screenshot 2024-05-06 140236](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/15c260d3-8e60-4bb6-8e17-1676517d54a5)

### Operasi pada Stack
Adapun operasi-operasi/fungsi yang dapat dilakukan pada stack adalah sebagai berikut [2] :
1. ```Push``` : digunakan untuk menambah item pada stack pada tumpukan paling atas
2. ```Pop``` : digunakan untuk mengambil item pada stack pada tumpukan paling atas
3. ```Clear``` : digunakan untuk mengosongkan stack
4. ```Create Stack``` : membuat tumpukan baru dengan jumlah elemen kosong
5. ```MakeNull``` : mengosongkan tumpukan jika ada elemen maka semua elemen dihapus
6. ```IsEmpty``` : fungsi yang digunakan untuk mengecek apakah stack sudah kosong
7. ```IsFull``` : fungsi yang digunakan untuk mengecek apakah stack sudah penuh

### Karakteristik Stack
Dari  operasi  yang  dilakukan  diperoleh  bahwa  karakteristik  dari suatu Stack adalah [3] : 
1. Elemen Stack yaitu item-item data yang terdapat dalam Stack. 
2. Top menunjukkan posisi puncak pada Stack. 
3. Max menunjukkan banyaknya maksimum item dari Stack. 
4. Stack  Kosong tidak  mungkin  dilakukan  POP  karena akan terjadi kesalahan yang disebut underflow. Underflow terjadi karena tidak ada item yang dapat dihapus dari Stack kosong.
5. Stack  Penuh tidak  mungkin  dilakukan  PUSH  karena akan terjadi kesalahan yang disebut overflow. Overflow terjadi karena tidak ada ruang tersisa dalam Stack untuk menyimpan item baru.

## Guided 

```C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] == "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }

}

void destroyArrayBuku () {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh?" << isFull() << endl;
    cout << "Apakah data stack kosong?" << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus:" << top << endl;
    cetakArrayBuku();
    return 0;
}
```
Kode di atas mengimplementasikan mengimplementasikan struktur data stack (tumpukan) untuk mengelola daftar buku. Program ini memiliki beberapa fungsi, seperti ```pushArrayBuku``` untuk menambahkan buku ke dalam stack, ```popArrayBuku``` untuk menghapus buku dari stack, ```peekArrayBuku``` untuk melihat buku pada posisi tertentu, ```countStack``` untuk menghitung jumlah buku dalam stack, ```changeArrayBuku``` untuk mengubah buku pada posisi tertentu, dan ```destroyArrayBuku``` untuk menghapus semua buku dari stack. Terakhir, program ini juga memiliki fungsi ```cetakArrayBuku``` untuk mencetak semua buku dalam stack.

## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& input) {
    int start = 0;
    int end = input.length() - 1;

    while (start < end) {
        if (input[start] != input[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    while (true) {
        string input;
        cout << "Masukan Kalimat : ";
        getline(cin, input);

        if (input == "STOP" || input == "stop") {
            break;
        }

        if (isPalindrome(input)) {
            cout << "Kalimat tersebut adalah Palindrom" << endl;
        } else {
            cout << "Kalimat tersebut bukan Palindrom" << endl;
        }

        char response;
        cout << "Apakah Anda ingin mencoba lagi (y/n)? ";
        cin >> response;

        if (tolower(response) != 'y') {
            break;
        }

        // Clear the input buffer
        cin.ignore();
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-05-06 113935](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/d79670d7-fe11-42ad-a9f7-482aebc03b89)

Kode di atas adalah program sederhana yang memeriksa apakah string input yang diberikan adalah palindrom atau bukan. Palindrom adalah sebuah kata, frasa, angka, atau urutan karakter lain yang dibaca sama maju dan mundur, mengabaikan spasi, tanda baca, dan huruf besar.

Program ini mendefinisikan fungsi yang disebut ```isPalindrome``` yang mengambil referensi konstan ke string sebagai argumen dan mengembalikan nilai boolean yang menunjukkan apakah string tersebut palindrom atau bukan. Fungsi ```isPalindrome``` bekerja dengan mengulang string dari kedua ujungnya ke tengah, membandingkan setiap karakter dengan karakter yang sesuai dari ujung lainnya. Jika menemukan pasangan karakter yang tidak cocok, fungsi ini akan segera mengembalikan nilai false. Jika berhasil memeriksa semua karakter tanpa menemukan ketidakcocokan, maka akan mengembalikan nilai true. Kemudian pada fungsi utama, user bisa memasukkan kalimat yang diinginkan dan program akan mencetak apakah kalimat tersebut merupakan palindrome atau bukan. Program ini menggunakan looping if else yang mana akan berhenti jika user ingin berhenti. 

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat
string reverseWord(string word) {
    stack<char> stack;
    for (char c : word) {
        stack.push(c);
    }
    string reversed = "";
    while (!stack.empty()) {
        reversed += stack.top();
        stack.pop();
    }
    return reversed;
}

// Fungsi utama untuk membalikkan kalimat
string reverseSentence(string sentence) {
    stack<string> stack;
    string word = "";
    for (char c : sentence) {
        if (c == ' ') {
            stack.push(word);
            word = "";
        } else {
            word += c;
        }
    }
    stack.push(word);
    string reversed = "";
    while (!stack.empty()) {
        reversed += reverseWord(stack.top()) + " ";
        stack.pop();
    }
    return reversed.substr(0, reversed.size() - 1);
}

int main() {
    cout << "Masukkan kalimat: ";
    string sentence;
    getline(cin, sentence);
    cout << "Kalimat yang dibalik: " << reverseSentence(sentence) << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-05-06 114218](https://github.com/shafasyahii/Praktikum-Struktur-Data-Assignment/assets/162096931/30a7a387-c33d-4e01-8fa7-e6633ae20c37)

Kode di atas adalah program yang membalikkan urutan kata dalam kalimat menggunakan stack. Program ini memiliki dua fungsi, yaitu ```reverseWord()``` dan ````reverseSentence()````.

Fungsi ```reverseWord()``` digunakan untuk membalikkan urutan karakter dalam sebuah kata. Fungsi ini menerima sebuah string sebagai parameter, kemudian memasukkan setiap karakter dari string tersebut ke dalam stack. Setelah itu, fungsi ini membuat string baru dengan mengambil karakter dari stack dan memasukkannya ke dalam string tersebut. Kemudian fungsi ```reverseSentence()``` digunakan untuk membalikkan urutan kata dalam sebuah kalimat. Fungsi ini menerima sebuah string sebagai parameter, kemudian memecah string tersebut menjadi beberapa kata berdasarkan spasi. Setiap kata yang dipecahkan kemudian dimasukkan ke dalam stack. Setelah itu, fungsi ini membuat string baru dengan mengambil kata dari stack dan membalikkan urutan karakter dari kata tersebut menggunakan fungsi ```reverseWord()```.

Terakhir, di bagian ```main()```, program meminta pengguna untuk memasukkan sebuah kalimat. Setelah itu, program akan memanggil fungsi ```reverseSentence()``` untuk membalikkan urutan kata dalam kalimat tersebut. Hasilnya kemudian akan ditampilkan ke layar.

## Kesimpulan

Stack adalah struktur data yang menggunakan metode LIFO (Last In First Out) di mana elemen terakhir yang masuk menjadi yang pertama keluar. Elemen stack hanya dapat diakses dari puncak (top). Stack dapat diimplementasikan dengan array atau linked list.

Operasi yang dapat dilakukan pada stack adalah push (menambahkan elemen), pop (mengambil dan menghapus elemen), clear (mengosongkan), create stack (membuat stack baru), makeNull (mengosongkan stack), is_empty (memeriksa apakah stack kosong), dan is_full (memeriksa apakah stack penuh).

Stack memiliki karakteristik yaitu memiliki elemen yang disebut item data, memiliki top yang menunjukkan puncak stack, memiliki batas maksimum elemen (max), tidak dapat melakukan pop pada stack kosong (underflow), dan tidak dapat melakukan push pada stack penuh (overflow).

Stack bermanfaat untuk mengevaluasi ekspresi matematika, mengimplementasikan backtracking, menyimpan riwayat operasi, dan manajemen memori. Contoh penerapan stack adalah mesin kalkulator, web browser, kompiler, dan sistem operasi.

## Referensi
[1] J. Sihombing, “Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java,” J. Ilm. Infokom, vol. 7, no. 2, pp. 15–24, 2019.

[2] M. DIKI, “Pengertian Stack,” Strukt. Data, vol. 4, no. 1, pp. 88–100, 2017.

[3] S, R. A. (2021). Struktur Data. Bandung. 
