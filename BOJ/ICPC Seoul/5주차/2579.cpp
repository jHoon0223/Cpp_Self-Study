#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 301

using namespace std;

int N;

vector<int> v;
int dp[MAX];

void DP() {
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = v[3] + max(v[1], v[2]);
    
    for (int i=4; i<=N; i++) {
        dp[i] = v[i] + max(v[i-1] + dp[i-3], dp[i-2]);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;

    v.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> v[i];
    }
    DP();

    cout << dp[N] << '\n';

    return 0;
}