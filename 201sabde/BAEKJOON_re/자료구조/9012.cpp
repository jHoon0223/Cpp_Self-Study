#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T-->0) {
        string s;
        cin >> s;

        stack<char> st;

        for (int i=0; i<s.length(); i++) {
            if(s[i]=='(') {
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.push(s[i]);
                    st.pop();
                    st.pop();
                }
                else 
                    st.push(s[i]);
            }
        }

        if (st.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}