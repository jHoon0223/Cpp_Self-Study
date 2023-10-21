#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    int i=1;

    while(t-->0) {
        int a,b;
        cin >> a >> b;

        printf("Case #%d: %d\n", i, a+b);

        i++;
    }

    return 0;
}