#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    double a,b;
    cin >> a >> b;

    double c = (double)a / (double)b;
    printf("%.9f\n", c);

    return 0;
}