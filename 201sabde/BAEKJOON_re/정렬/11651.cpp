#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(), v.end());

    for (int i=0; i<N; i++)
        printf("%d %d\n", v[i].second, v[i].first);

    return 0;
}