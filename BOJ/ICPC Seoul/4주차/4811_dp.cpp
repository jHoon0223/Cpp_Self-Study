#include <iostream>

using namespace std;
 
long long dp[33][33];
 
int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    for (int h=0; h<=30; h++) {
        for (int w=0; w<=30; w++) {
            if (h > w) continue;

            if (h == 0) dp[w][h] = 1;

            else dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
        }
    }

    while (1) {
        int N;
        cin >> N;

        if (N == 0) break;

        cout << dp[N][N] << "\n";
    }
}
