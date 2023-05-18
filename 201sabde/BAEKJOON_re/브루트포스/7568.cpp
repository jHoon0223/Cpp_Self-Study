#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    while(N-->0) {
        int a, b;
        cin >> a >> b;

        v.push_back(make_pair(a,b));
    }

    vector<int> total;
    for (int i=0; i<v.size(); i++) {
        int cnt = 0;

        int x = v[i].first;
        int y = v[i].second;

        for (int j = 0; j<v.size(); j++)
            if (x < v[j].first && y < v[j].second) cnt++;

        total.push_back(cnt);
    }

    for (int i=0; i<total.size(); i++)
        cout << total[i]+1 << ' ';

    return 0;
}