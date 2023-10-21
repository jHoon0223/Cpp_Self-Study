#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int X, N;
    cin >> X >> N;

    int total = 0;
    while(N-->0) {
        int a, b;
        cin >> a >> b;

        total += a*b;
    }

    if (total == X) printf("Yes\n");
    else printf("No\n");

    return 0;
}