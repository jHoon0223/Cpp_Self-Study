#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N+1; i++) {
        int cnt = i;
        int cnt_s = N-i;
        while (cnt_s-->0) {
            cout << " ";
        }
        while (cnt-->0) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}