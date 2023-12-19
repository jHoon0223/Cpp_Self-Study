#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int p,q;
    cin >> p >> q;

    vector<int> v;
    for (int i=p; i>=1; i--) {
        if (v.size() == q) break;

        if (p%i==0) v.push_back(p/i);
    }
    if (v.size() < q) cout << "0\n";
    else cout << v[q-1] << '\n';

    return 0;
}