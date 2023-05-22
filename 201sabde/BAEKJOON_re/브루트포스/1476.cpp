#include <iostream>
#include <stdio.h>

using namespace std;

int ansE, ansS, ansM;
int E=1, S=1, M=1;
int cnt=1;

void correct() {
    if (E>15) E=1;
    if (S>28) S=1;
    if (M>19) M=1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> ansE >> ansS >> ansM;

    while(1) {
        if (ansE==E && ansS==S && ansM==M) {
            printf("%d\n", cnt);
            break;
        }
        else {
            E++; S++; M++; cnt++;

            correct();
        }
    }
    
    return 0;
}