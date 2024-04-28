#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string nama;
    string nim;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = NULL; }
    void addNode(string nama, string nim);
    void addNodeAtPos(string nama, string nim, int pos);
    void updateNode(string nama, string nim, int pos);
    void deleteNode(int pos);
    void displayList();
    void deleteList();
};

void LinkedList::addNode(string nama, string nim) {
    Node* temp = new Node();
    temp->nama = nama;
    temp->nim = nim;
    temp->next = head;
    head = temp;
}

void LinkedList::addNodeAtPos(string nama, string nim, int pos) {
    Node* temp1 = new Node();
    Node* temp2 = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp2 != NULL) {
            temp2 = temp2->next;
        }
    }
    if (temp2 == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    temp1->nama = nama;
    temp1->nim = nim;
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void LinkedList::updateNode(string nama, string nim, int pos) {
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp != NULL) {
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    temp->nama = nama;
    temp->nim = nim;
}

void LinkedList::deleteNode(int pos) {
    Node* temp1 = head;
    Node* temp2 = NULL;
    for (int i = 1; i < pos; i++) {
        if (temp1 != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }
    if (temp1 == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (temp2 == NULL) {
        head = temp1->next;
    }
    else {
        temp2->next = temp1->next;
    }
    delete temp1;
}

void LinkedList::displayList() {
    Node* temp = head;
    cout << endl << "==================================" << endl;
    cout << left << setw(15) << "Nama" << setw(15) << "NIM" << endl;
    cout << "==================================" << endl;
    while (temp != NULL) {
        cout << left << setw(15) << temp->nama << setw(15) << temp->nim << endl;
        temp = temp->next;
    }
    cout << "==================================\n" << endl;
}

void LinkedList::deleteList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = NULL;
}

int main() {
    LinkedList list;
    int choice, position;
    string name, nim;
    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n" << endl;
        cout << "-------- Main Menu --------\n" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR\n" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Tambah Depan" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.addNode(name, nim);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            cout << "Tambah Belakang" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.addNodeAtPos(name, nim, 0);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            cout << "Tambah Tengah" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> position;
            list.addNodeAtPos(name, nim, position);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            cout << "Ubah Depan" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.updateNode(name, nim, 1);
            cout << "Data telah diubah" << endl;
            break;
        case 5:
            cout << "Ubah Belakang" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            list.updateNode(name, nim, 0);
            cout << "Data telah diubah" << endl;
            break;
        case 6:
            cout << "Ubah Tengah" << endl;
            cout << "Masukkan Nama : ";
            cin >> name;
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> position;
            list.updateNode(name, nim, position);
            cout << "Data telah diubah" << endl;
            break;
        case 7:
            cout << "Hapus Depan" << endl;
            list.deleteNode(1);
            cout << "Data telah dihapus" << endl;
            break;
        case 8:
            cout << "Hapus Belakang" << endl;
            list.deleteNode(0);
            cout << "Data telah dihapus" << endl;
            break;
        case 9:
            cout << "Hapus Tengah" << endl;
            cout << "Masukkan Posisi : ";
            cin >> position;
            list.deleteNode(position);
            cout << "Data telah dihapus" << endl;
            break;
        case 10:
            cout << "Hapus List" << endl;
            list.deleteList();
            cout << "Data telah dihapus" << endl;
            break;
        case 11:
            cout << "TAMPILKAN" << endl;
            list.displayList();
            break;
        case 0:
            cout << "KELUAR\n" << endl;
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid\n" << endl;
            break;
        }
    }
    return 0;
}