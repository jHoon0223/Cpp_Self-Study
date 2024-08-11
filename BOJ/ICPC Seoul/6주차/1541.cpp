#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> st;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;

    string tmp;
    int ans = 0;

    bool flag = false;
    for (int idx=0; idx<=s.length(); idx++) {
        if (s[idx] == '+' || s[idx] == '-' || idx == s.length()) {
            if (flag) {
                ans -= stoi(tmp);
                tmp.clear();
            }
            else {
                ans += stoi(tmp);
                tmp.clear();
            }
        }
        else {
            tmp = tmp + s[idx];
        }

        if (s[idx] == '-') {
            flag = true;
        }
    }

    cout << ans << '\n';

    return 0;
}