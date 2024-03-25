#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int dataArray[size];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> dataArray[i];
    }

    cout << "Data Array: ";
    for(int i = 0; i < size; i++) {
        cout << dataArray[i] << " ";
    }

    cout << "\nNomor Genap: ";
    for(int i = 0; i < size; i++) {
        if(dataArray[i] % 2 == 0) {
            cout << dataArray[i] << " ";
        }
    }

    cout << "\nNomor Ganjil: ";
    for(int i = 0; i < size; i++) {
        if(dataArray[i] % 2 != 0) {
            cout << dataArray[i] << " ";
        }
    }

    return 0;
}