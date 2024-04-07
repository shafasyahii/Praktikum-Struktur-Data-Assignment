#include <iostream>
#include <string>

using namespace std;

int main() {
    string sentence;
    int vowel_count = 0;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for (char c : sentence) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowel_count++;
        }
    }

    cout << "Number of vowels: " << vowel_count << endl;

    return 0;
}