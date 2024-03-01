#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int,int>> v;
    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(b,a));
    }
    
    int cnt=1;
    sort(v.begin(), v.end());

    int endingTime = v[0].first;
    for (int i=1; i<N; i++) {
        if (endingTime <= v[i].second) {
            endingTime = v[i].first;
            cnt++;
        }

    }

    cout << cnt << '\n';

    return 0;
}