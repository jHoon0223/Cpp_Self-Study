#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N==1) {
        printf("0\n");
        return 0;
    }

    int i;
    for (i=1; i<N; i++) {
        int sum = i;

        string str = to_string(i);
        for (int j=0; j<str.length(); j++) 
            sum += (str[j]-48);

        if (sum == N) {
            printf("%d\n", i);
            return 0;
        }        
    }
    printf("0\n");

    return 0;
}