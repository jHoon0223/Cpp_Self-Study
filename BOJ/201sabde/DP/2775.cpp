#include <iostream>

using namespace std;

int dp[15][15];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i=1; i<15; i++) {
        dp[0][i] = i;
    }
    for (int i=1; i<15; i++) {
        dp[i][1] = 1;
    }

    while(T-->0) {
        int k,n;
        cin >> k >> n;

        for (int i=1; i<k+1; i++) {
            for (int j=2; j<n+1; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        printf("%d\n", dp[k][n]);
    }

    return 0;
}