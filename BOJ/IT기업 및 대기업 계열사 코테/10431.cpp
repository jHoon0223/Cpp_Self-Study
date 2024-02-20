#include <iostream>

#define MAX 21

using namespace std;

int arr[MAX];

int main() {
    int P;
    cin >> P;

    while (P-->0) {
        int a;
        cin >> a;
        int res = 0;

        for (int i=0; i<20; i++) {
            int st;
            cin >> st;
            arr[i] = st;
        }

        for (int i=19; i>=0; i--) {
            int target = arr[i];
            int cnt = 0;

            for (int j=0; j<i; j++) {
                if (arr[j] > target) cnt++;
            }
            res += cnt;
        }
        cout << a << ' ' << res << '\n';
    }

    return 0;
}