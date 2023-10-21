#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    if (s.empty()) cout << 0 << '\n';
    else if (s.length() == 1 && s.front() == ' ') cout << 0 << '\n';
    else {
        int cnt = 0;
        for (int i=1; i<s.length()-1; i++)
            if (s[i] == ' ') cnt++;

        cout << cnt+1 << '\n';
    }

    return 0;
}