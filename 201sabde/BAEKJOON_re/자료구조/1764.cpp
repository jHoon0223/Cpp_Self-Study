#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> m;
    vector<string> v;
    for (int i=0; i<N+M; i++) {
        string s;
        cin >> s;
        m[s]++;
        if (m[s] > 1) v.push_back(s);
    }
    sort(v.begin(), v.end());

    cout << v.size() << '\n';
    for (string i:v) cout << i << '\n';

    return 0;
}