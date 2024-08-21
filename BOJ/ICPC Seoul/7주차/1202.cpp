#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 300001

using namespace std;

int N,K;

pair<int,int> jw[MAX];
int bag[MAX];

priority_queue<int> pq;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a >> b;

        jw[i] = make_pair(a,b);
    }

    for (int i=0; i<K; i++) {
        int a;
        cin >> a;

        bag[i] = a;
    }

    sort(jw, jw+N);
    sort(bag, bag+K);

    int idx=0;
    long long sum=0;

    for (int target_bag=0; target_bag<K; target_bag++) {
        while (idx < N && jw[idx].first <= bag[target_bag]) {
            pq.push(jw[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << '\n';

    return 0;
}