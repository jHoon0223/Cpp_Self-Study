#include <iostream>

using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;

    long long i, target;
    for (i = 665; cnt < N; i++) {
        target = i;

        while (target > 665) {
            if (target % 1000 == 666) {
                cnt++;
                break;
            }
            else target /= 10;
        }
    }
    cout << i-1;

    return 0;
}