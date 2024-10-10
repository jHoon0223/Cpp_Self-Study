#include <iostream>

#define MAX 102

using namespace std;

long long dp[MAX];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int T;
    cin >> T;

    //  dp 최적화
    dp[0] = 1; dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] = 2;
    for (int i=5; i<MAX; i++) 
        dp[i] = dp[i-1] + dp[i-5];

    while (T-->0) {
        int a;
        cin >> a;
        cout << dp[a-1] << '\n';
    }

    return 0;
}