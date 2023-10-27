#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int cnt=0;
    if (N==1) cout << 1 << endl;
    else {
        N--; cnt++;

        for (int i=1; ; i++) {
            N -= 6*i; cnt++;

            if (N <=0) break;
        }
        cout << cnt << endl;
    }

    return 0;
}