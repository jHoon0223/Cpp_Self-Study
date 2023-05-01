#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int cnt=99;
    int a,b,c;
    if (N<100) printf("%d\n", N);
    else {
        for (int i=100; i<=N; i++) {
            a = i/100;
            b = i/10 - a*10;
            c = i%10;

            if (a-b == b-c) cnt++;
            else continue;
        }
        printf("%d\n", cnt);
    }

    return 0;
}