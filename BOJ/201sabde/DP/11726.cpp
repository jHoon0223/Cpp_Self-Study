#include <iostream>

#define MAX 1001

using namespace std;

int dp[MAX];

int main() {
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=N; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }
    cout << dp[N] << '\n';

    return 0;
}