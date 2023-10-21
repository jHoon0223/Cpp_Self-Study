#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int total = 0;
    for (int i=0; i<v.size(); i++) {
        total += v[i] * N--;
    }

    cout << total << endl;

    return 0;
}