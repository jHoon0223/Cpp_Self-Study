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
    for (int i=0; i<N+M; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (int i : v) printf("%d ", i);

    return 0;
}