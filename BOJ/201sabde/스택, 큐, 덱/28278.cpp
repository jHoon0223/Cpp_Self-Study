#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;
    while(N-->0) {
        int num;
        cin >> num;

        if (num==1) {
            int a;
            cin >> a;

            s.push(a);
        }
        else if (num==2) {
            if (s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() << '\n';
            s.pop();
        }
        else if (num==3) cout << s.size() << '\n';
        else if (num==4) s.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
        else if (num==5) {
            if (s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() << '\n';
        }
    }

    return 0;
}