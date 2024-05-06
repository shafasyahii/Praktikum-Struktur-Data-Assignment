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