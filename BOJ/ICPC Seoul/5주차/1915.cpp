#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 1005

using namespace std;

int N,M;
int arr[MAX][MAX];
int dp[MAX][MAX];
int maxLen = 0;

void SOL() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (arr[i][j] == 0) continue;

            int L = dp[i][j-1];
            int LT = dp[i-1][j-1];
            int T = dp[i-1][j];

            dp[i][j] = min(min(L,LT), T) + 1;

            maxLen = max(maxLen, dp[i][j]);
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        string s;
        cin >> s;
        
        for (int j=0; j<M; j++) {
            arr[i][j+1] = s[j] - '0';
        }
    }
    //입력 받기

    SOL();

    cout << pow(maxLen, 2) << '\n';

    return 0;
}