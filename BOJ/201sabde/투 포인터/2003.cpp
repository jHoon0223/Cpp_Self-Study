#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    //sort(v.begin(), v.end());

    int front=0, back=0;
    int cnt = 0, partial_sum = 0;
    while(1) {
        if (partial_sum >= M) {
            partial_sum -= v[front];
            front++;
        }
        else if (back == N) break;
        else {
            partial_sum += v[back];
            back++;
        }

        if (partial_sum == M) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}