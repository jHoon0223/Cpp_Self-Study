#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define INF 2000000000

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
    sort(v.begin(), v.end());

    int front=0, back=0;
    int result = INF;

    while(front < N && back < N) {
        int minus = v[back] - v[front];

        if (minus < M) back++;
        else {
            result = min(minus, result);
            front++;
        }
    }

    printf("%d\n", result);

    return 0;
}