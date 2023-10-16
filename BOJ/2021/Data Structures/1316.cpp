#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int total = N;

    int cnt = 0;
    while(N-->0) {
        bool arr[26] = { false };
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            int index = s[i]-97;
            if (arr[index] == false) {
                arr[index] = true;
            }
            else if (arr[index] == true && s[i] != s[i-1]) {
                cnt++;
                break;
            }
            else if (arr[index] == true && s[i] == s[i-1])
                continue;
        }
    }
    cout << total-cnt;

    return 0;
}