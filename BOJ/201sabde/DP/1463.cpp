#include <iostream>
#include <stdio.h>

using namespace std;

int dp[1000002];

int main() {
    int N;
    cin >> N;

    dp[1] = 0; dp[2] = 1; dp[3] = 1;

    if (N<4) printf("%d\n", dp[N]);
    else {
        for (int i=4; i<=N; i++) {
            dp[i] = dp[i-1]+1;

            if (i%3==0) dp[i] = min(dp[i/3]+1, dp[i]);
            if (i%2==0) dp[i] = min(dp[i/2]+1, dp[i]);
        }
        printf("%d\n", dp[N]);
    }

    return 0;
}