#include <iostream>

#define MAX 1000001

using namespace std;

int dp[MAX];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    cout << dp[N] << '\n';

    return 0;
}