#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int idx = N-k;
    cout << v[idx] << endl;

    return 0;
}