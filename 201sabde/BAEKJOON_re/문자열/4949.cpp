#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

string s;

int main() {
    while (1) {        
        getline(cin, s);

        stack<char> st;

        if (s[0] == '.') break;

        for (int i=0; i<s.length()-1; i++) {
            if (s[i] == '(') st.push('(');

            if (s[i] == '[') st.push('[');

            if (s[i] == ')') {
                if (!st.empty() && st.top() == ')') st.pop();
                else cout << "no" << endl; break;
            }

            if (s[i] == ']') {
                if (!st.empty() && st.top() == ']') st.pop();
                else cout << "no" << endl; break;
            }

            if (st.empty() && i == s.length()-2) cout << "yes" << endl;
            else if (!st.empty() && i == s.length()-2) cout << "no" << endl;
        }
    }

    return 0;
}