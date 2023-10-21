#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    int a;
    cin >> a;

    char s[101];
    scanf("%s", &s);

    int sum = 0;
    for (int i=0; i<a; i++)
        sum += s[i] - 48;
    cout << sum << endl;

    return 0;
}