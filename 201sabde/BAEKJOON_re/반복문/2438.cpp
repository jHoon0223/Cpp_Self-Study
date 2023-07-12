#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a;
    cin >> a;

    for (int i=1; i<=a; i++) {
        for (int j=1; j<=i; j++) {
            printf("*");
        }
        cout << endl;
    }

    return 0;
}