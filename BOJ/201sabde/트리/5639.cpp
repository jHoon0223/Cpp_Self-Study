#include <iostream>

using namespace std;

int arr[10001];

void F(int start, int end) {
    if (start >= end) return;

    int root = arr[start];
    int idx = start+1;

    while(idx < end){
        if(root < arr[idx]) break;
        idx++;
    }

    F(start+1, idx);
    F(idx, end);

    cout << arr[start] << '\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int a;
    int n=0;

    while(cin >> a) arr[n++] = a;

    F(0, n);

    return 0;
}