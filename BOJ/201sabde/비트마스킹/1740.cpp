#include <iostream>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    long long N;
    cin >> N;

    long long total = 0, s = 1;
    while (N) {
        if (N & 1) total += s;
        s *= 3;

        N >>= 1;
    }

    cout << total << '\n';

    return 0;
}