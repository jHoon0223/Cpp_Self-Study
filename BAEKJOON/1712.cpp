#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if ((C - B) == 0) {
        cout << -1;
    }
    else {
        int x = A / (C - B) + 1;

        if (x <= 0)
            cout << -1;
        else
            cout << x;
    }

    return 0;
}