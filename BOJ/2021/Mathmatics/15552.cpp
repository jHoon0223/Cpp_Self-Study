#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    while(T-->0) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }

    return 0;
}