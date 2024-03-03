#include <iostream>

#define MAX 130

using namespace std;

int cnt0, cnt1;
int arr[MAX][MAX];

void F(int x, int y, int n) {
    int tmp = 0;
    
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            if (arr[i][j] == 1) tmp++;
        }
    }

    if (tmp == 0) cnt0++;
    else if (tmp == n*n) cnt1++;
    else {
        F(x, y, n/2);
        F(x + n/2, y, n/2);
        F(x, y + n/2, n/2);
        F(x + n/2, y + n/2, n/2);
    }

    return ;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a;
            cin >> a;

            arr[i][j] = a;
        }
    }

    F(0,0,N);

    cout << cnt0 << '\n' << cnt1 << '\n';

    return 0;
}