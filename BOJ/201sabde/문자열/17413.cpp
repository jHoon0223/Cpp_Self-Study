#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    getline(cin, s);

    string tmp, ans;
    bool tag_flag = false;
    for (int i=0; i<=s.size(); i++) {
        if (tag_flag) {
            if (s[i] == '>') tag_flag = false;
            
            ans.push_back(s[i]);
            continue;
        }

        if (s[i] == ' ') {
            if (!tmp.empty()) {
                reverse(tmp.begin(), tmp.end());
                ans.append(tmp);
                tmp.clear();
                ans.push_back(' ');
                continue;
            }
        }
        else if (s[i] == '\0') {
            if (!tmp.empty()) {
                reverse(tmp.begin(), tmp.end());
                ans.append(tmp);
                tmp.clear();
                ans.push_back(' ');
                continue;
            }
        }
        else if (s[i] == '<') {
            tag_flag = true;

            if (!tmp.empty()) {
                reverse(tmp.begin(), tmp.end());
                ans.append(tmp);
                tmp.clear();
            }

            ans.push_back(s[i]);
            continue;
        }
        else {
            tmp.push_back(s[i]);
        }
    }

    cout << ans << endl;

    return 0;
}