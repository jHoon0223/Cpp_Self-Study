#include <iostream>

using namespace std;

#define MAX 10001

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int arr[MAX] = { 0, };
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        arr[a]++;
    }

    for (int i=0; i<MAX; i++) {
        if (arr[i] == 0) continue;
        else {
            for (int j=0; j<arr[i]; j++) {
            cout << i << '\n';
            }
        }
    }

    return 0;
}