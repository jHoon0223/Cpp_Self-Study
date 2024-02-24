#include <iostream>

using namespace std;

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int cnt=0;
    if (N == 0) {
        cout << 1 << '\n';
        return 0;
    }

    int newN;
    int tmp=N;
    while (1) {
        newN = ((tmp%10)*10) + ((tmp/10 + tmp%10)%10);
        cnt++;

        if (N == newN) break;

        tmp = newN;
    }
    cout << cnt << '\n';

    return 0;
}