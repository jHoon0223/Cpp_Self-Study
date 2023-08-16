#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt=0;
    while(N-->0) {
        bool arr[26] = { false, };
        
        string s;
        cin >> s;

        arr[s[0]-97] = true;

        for (int i=1; i<s.length(); i++) {
            int index = s[i] - 97;

            if (arr[index] == false) arr[index] = true;
            else {
                if (s[i] == s[i-1]) continue;
                else {
                    cnt--;
                    break;
                }
            }
        }
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}