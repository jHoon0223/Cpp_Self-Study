#include <stdio.h>

using namespace std;

int main() {
    while(1) {
        int a,b;
        if(scanf("%d %d", &a, &b) == EOF) break;
        printf("%d\n", a+b);
    }

    return 0;
}