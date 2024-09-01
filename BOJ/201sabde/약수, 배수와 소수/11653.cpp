#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    if (N==1) return 0;

    int idx = 2;
    vector<int> v;
    while (1) {
        if (N == 1) break;

        if (N % idx == 0) {
            v.push_back(idx);
            N /= idx;
        }
        else idx++;
    }

    sort(v.begin(), v.end());

    for (int a : v) cout << a << '\n';

    return 0;
}