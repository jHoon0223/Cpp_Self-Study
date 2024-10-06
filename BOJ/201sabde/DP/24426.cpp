#include <iostream>

#define MAX 40

using namespace std;

int N;
int f[MAX];
int cnt1=0, cnt2=0;

int fib1 (int n) {
    if (n==1 || n==2) {
        cnt1++;
        return 1;
    }
    else return (fib1(n-1) + fib1(n-2));
}

int fib2 (int n) {
    for (int i=3; i<=N; i++) {
        cnt2++;
        f[i] = f[i-1] + f[i-2];
    }        
    
    return f[n];
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> N;

    f[1] = 1; f[2] = 1;

    fib1(N);
    fib2(N);

    cout << cnt1 << ' ' << cnt2 << '\n';

    return 0;
}