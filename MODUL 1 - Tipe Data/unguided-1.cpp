#include <iostream>
using namespace std;

// int untuk bilangan bulat
int add(int a, int b) {
    return a + b;
}

// float untuk bilangan desimal
float subtract(float a, float b) {
    return a - b;
}

// Main program
int main() {
    int a = 5, b = 3;
    int result1;
    float result2;

    // Memanggil fungsi add dan menampilkan hasilnya
    result1 = add(a, b);
    cout << "Addition: " << result1 << endl;

    // Memanggil fungsi substract dan menampilkan hasilnya
    result2 = subtract(5.5, 2.5);
    cout << "Subtraction: " << result2 << endl;

    return 0;
}
