#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int A,B,V;
    cin >> A >> B >> V;

    V = V-A;

    if (V==0) {
        cout << 1 << endl;
        return 0;
    }

    int r = A-B;
    int cnt = 1;
    if (V >= r) {
        if (V%r == 0) cnt += V/r;
        else {
            cnt += V/r+1;
        }
    }
    else {
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}