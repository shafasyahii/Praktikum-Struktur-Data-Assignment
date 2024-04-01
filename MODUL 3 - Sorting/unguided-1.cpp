#include <iostream>
using namespace std;

void selection_sort(float arr[], int length) {
    int i, j, min;
    float temp;

    for (i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] > arr[min]) {
                min = j;
            }
        }

        // Swap the elements
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print_array(float arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    float arr[5] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "Indeks Prestasi Semester before sorting: " << endl;
    print_array(arr, length);

    selection_sort(arr, length);

    cout << "\nIndeks Prestasi Semester after sorting: " << endl;
    print_array(arr, length);
}