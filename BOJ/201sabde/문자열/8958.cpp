#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        bool flag = false;
        int score = 0;
        int cnt=0;

        for (int i=0; i<s.size(); i++) {
            if (flag) {
                if (s[i] == 'O') {
                    flag = true;
                    cnt++;
                    score += cnt;
                }
                else if (s[i] == 'X') {
                    flag = false;
                    cnt = 0;
                }
            }
            else {
                if (s[i] == 'O') {
                    flag = true;
                    cnt++;
                    score += cnt;
                }
                else if (s[i] == 'X') {
                    flag = false;
                    cnt = 0;
                }
            }
        }

        cout << score << '\n';
    }

    return 0;
}