//#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

/*void setting() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}*/

void H(int n, int first, int mid, int last) {
    if (n == 1) {
        //cout << first << " " << last << endl;
        printf("%d %d\n", first, last);
        return;
    }
    else {
        H(n-1, first, last, mid);
        H(1, first, mid, last);
        H(n-1, mid, first, last);
    }
}

int main() {
    //setting();
    int N;
    //cin >> N;
    scanf("%d", &N);

    //cout << pow(2, N)-1 << endl;
    printf("%d\n", (int)pow(2, N)-1 );
    H(N, 1, 2, 3);

    return 0;
}