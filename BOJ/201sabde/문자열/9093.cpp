#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cin.ignore();

    while (N-->0) {
        string s;
        getline(cin, s);

        string tmp, ans;
        for (int i=0; i<=s.size(); i++) {
            if (s[i] == ' ' || s[i] == '\0') {
                reverse(tmp.begin(), tmp.end());
                ans.append(tmp);
                ans.push_back(' ');
                tmp.clear();
            }
            else {
                tmp.push_back(s[i]);
            }
        }
        reverse(s.begin(), s.end());
        cout << ans << endl;
    }

    return 0;
}