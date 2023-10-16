#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int total = A * B * C;

    int result[10] = { };
    while (total != 0) {
        int idx = total % 10;
        total /= 10;

        result[idx]++;
    }

    for (int i = 0; i < 10; i++)
        cout << result[i] << endl;

    return 0;
}