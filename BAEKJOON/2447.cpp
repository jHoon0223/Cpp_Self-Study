#include <iostream>

using namespace std;

void star(int n, int x, int y) {
    if (x/n%3 == 1 && y/n%3 == 1)
        cout << " ";
    else {
        if (n/3 == 0)
            cout << "*";
        else
            star(n/3, x, y);
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            star(N, i, j);
        }
        cout << endl;
    }

    return 0;
}