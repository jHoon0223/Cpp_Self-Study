#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i=1; i<=9; i++)
        printf("%d * %d = %d\n", N, i, N*i);

    return 0;
}