#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int C,N;
int total = 0;

multiset<int> chk;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> C >> N;

    for (int i=0; i<C; i++) {
        int a;
        cin >> a;

        chk.insert(a);
    }

    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;

        cow.push(make_pair(b,a));
    }

    while (!cow.empty()) {
        int start = cow.top().second;
        int end = cow.top().first;

        auto iter = chk.lower_bound(start);

        if (iter != chk.end() && (*iter) <= end) {
            total++;
            chk.erase(iter);
        }

        cow.pop();
    }    

    cout << total << '\n';

    return 0;
}