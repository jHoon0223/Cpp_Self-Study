#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int total = 0;

    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;

        if (a%2 == 1) {
            v.push_back(a);
            total += a;
        }
    }

    if (v.empty())
        cout << -1;
    else {
        sort(v.begin(), v.end());
        cout << total << '\n' << v.front();
    }

    return 0;
}