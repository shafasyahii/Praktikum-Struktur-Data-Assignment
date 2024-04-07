#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (data[i] == 4) {
            count++;
        }
    }

    cout << "The number of occurrences of 4 in the data is: " << count << endl;

    return 0;
}