#include <iostream>

using namespace std;

long long fac(int a) {
    if (a == 0) return 1;

    if (a == 1) return 1;
    else return (a * fac(a-1));
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    cout << fac(N) << '\n';

    return 0;
}