#include <iostream>

using namespace std;

int main() {
    int H, M;
    cin >> H >> M;

    if (M >= 45)
        cout << H << " " << M-45;
    else {
        int a = 60-(45-M);
        if (H == 0)
            cout << "23 " << a;
        else
            cout << H-1 << " " << a;
    }

    return 0;
}