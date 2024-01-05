#include <iostream>

using namespace std;

pair<char, char> arr[26];

void preOrder(char c) {
    if (c != '.') {
        cout << c;
        preOrder(arr[c-'A'].first);
        preOrder(arr[c-'A'].second);
    }
}

void inOrder(char c) {
    if (c != '.') {
        inOrder(arr[c-'A'].first);
        cout << c;
        inOrder(arr[c-'A'].second);
    }
}

void postOrder(char c) {
    if (c != '.') {
        postOrder(arr[c-'A'].first);
        postOrder(arr[c-'A'].second);
        cout << c;
    }
}

int main() {
    int N;
    cin >> N;

    while(N-->0) {
        char parent, left, right;
        cin >> parent >> left >> right;

        arr[parent-'A'].first = left;
        arr[parent-'A'].second = right;
    }

    preOrder('A');
    cout << endl;
    inOrder('A');
    cout << endl;
    postOrder('A');
    cout << endl;

    return 0;
}