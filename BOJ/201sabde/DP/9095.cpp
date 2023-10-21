#include <iostream>
#include <stdio.h>

using namespace std;

int dp[11];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    int T;
    cin >> T;

    for (int i=4; i<11; i++)
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];

    while(T-->0) {
        int a;
        cin >> a;

        printf("%d\n", dp[a]);
    }

    return 0;
}