#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt1 = 0, cnt0 = 0;
bool flag1 = false, flag0 = false;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;

    for (int i=0; i<s.length(); i++) {
        if (s[i] == '0') {
            if (flag0) continue;

            flag0 = true;
            flag1 = false;

            cnt0++;
        }
        else {
            if (flag1) continue;

            flag0 = false;
            flag1 = true;

            cnt1++;
        }
    }

    cout << min(cnt0, cnt1) << '\n';

    return 0;
}