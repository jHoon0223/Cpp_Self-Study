#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string>b) {
	return a.first < b.first;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, string>> v;
    for (int i=0; i<N; i++) {
        int a;
        string s;
        cin >> a >> s;

        v.push_back(make_pair(a,s));
    }
    stable_sort(v.begin(), v.end(), cmp);

    for (int i=0; i<N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}