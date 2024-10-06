#include <iostream>

#define MAX 21

using namespace std;

int dp[MAX][MAX][MAX];

int F(int a, int b, int c) {
    if (a<=0 || b<=0 || c<=0) 
        return 1;
    else if (a>20 || b>20 || c>20) 
        return F(20,20,20);
    else if (dp[a][b][c])
        return dp[a][b][c];
    else if (a<b && b<c) {
        dp[a][b][c] = F(a,b,c-1) + F(a,b-1,c-1) - F(a,b-1,c);
        return dp[a][b][c];
    }
    else {
        dp[a][b][c] = F(a-1,b,c) + F(a-1,b-1,c) + F(a-1,b,c-1) - F(a-1,b-1,c-1);
        return dp[a][b][c];
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    while (1) {
        int a,b,c;
        cin >> a >> b >> c;

        if (a==-1 && b==-1 && c==-1) break;

        int total = F(a,b,c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << total << '\n';
    }

    return 0;
}