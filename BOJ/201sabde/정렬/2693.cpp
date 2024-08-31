#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T-->0) {
        vector<int> v;

        for (int i=0; i<10; i++) {
            int a;
            cin >> a;

            v.push_back(a);
        }

        sort(v.begin(), v.end());

        cout << v[7] << '\n';
    }

    return 0;
}