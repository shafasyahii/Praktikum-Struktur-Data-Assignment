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