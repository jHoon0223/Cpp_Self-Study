#include <iostream>

using namespace std;

int main() {
    int arr[6];
    for (int i=0; i<6; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }

    arr[0] = 1 - arr[0];
    arr[1] = 1 - arr[1];
    arr[2] = 2 - arr[2];
    arr[3] = 2 - arr[3];
    arr[4] = 2 - arr[4];
    arr[5] = 8 - arr[5];

    for (int j=0; j<6; j++) cout << arr[j] << ' ';
    cout << endl;

    return 0;
}