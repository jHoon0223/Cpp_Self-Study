#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i < T+1; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", i, A, B, A+B);
    }

    return 0;
}