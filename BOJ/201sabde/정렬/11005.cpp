#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, B;
    cin >> N >> B;

    string s;

    while (N != 0) {
        int tmp = N % B;

        if (tmp <= 9) {
            s += ('0' + tmp);
        }
        else {
            tmp += 55;
            s += tmp;
        }

        N /= B;
    }
    reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}