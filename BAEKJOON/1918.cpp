#include <iostream>
#include <stack>

using namespace std;

int whoseFisrt(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    string s;
    cin >> s;

    int len = s.length();

    stack<char> stk;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 65 && s[i] <= 90) cout << s[i];
        else if (s[i] == '(') stk.push(s[i]);
        else if (s[i] == ')') {
            while(!stk.empty() && stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while (!stk.empty() && whoseFisrt(stk.top()) >= whoseFisrt(s[i])) {
                cout << stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}