#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);
    for (int i = 0; i < n; ++i) {
        cout << "Masukkan karakter ke-" << i + 1 << ": ";
        cin >> characters[i];
    }

    // Urutan sebelum sorting
    cout << "Urutan karakter sebelum sorting:\n";
    for (char c : characters) {
        cout << c << " ";
    }
    cout << "\n";

    // Ascending sort
    sort(characters.begin(), characters.end());
    cout << "Urutan karakter setelah ascending sort:\n";
    for (char c : characters) {
        cout << c << " ";
    }
    cout << "\n";

    // Descending sort
    sort(characters.rbegin(), characters.rend());
    cout << "Urutan karakter setelah descending sort:\n";
    for (char c : characters) {
        cout << c << " ";
    }
    cout << "\n";

    return 0;
}