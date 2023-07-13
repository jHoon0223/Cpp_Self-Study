#include <iostream>

using namespace std;

int main() {
    bool arr[30] = { false, };

    for (int i=0; i<28; i++) {
        int a;
        cin >> a;

        arr[a-1] = true;
    }

    for (int i=0; i<30; i++) {
        if (arr[i] == false) 
            cout << i+1 << ' ';
    }

    return 0;
}