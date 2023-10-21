#include <iostream>
#include <stdlib.h>

using namespace std;

int arr[15];
int N, cnt;

bool promising(int idx) {
    for (int i=0; i<idx; i++) {
        if (arr[idx] == arr[i] || idx-i == abs(arr[idx]-arr[i])) 
            return false;
    }
    return true;
}

void nQueen(int idx) {
    if (idx == N) {
        cnt++;
        return ;
    }

    for (int i=0; i<N; i++) {
        arr[idx] = i;

        if (promising(idx)) nQueen(idx+1);
    }
}

int main() {
    cin >> N;
    nQueen(0);
    cout << cnt << endl;

    return 0;
}