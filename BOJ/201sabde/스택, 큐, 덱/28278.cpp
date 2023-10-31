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
                cout << -1 << endl;
                continue;
            }
            cout << s.top() << endl;
            s.pop();
        }
        else if (num==3) cout << s.size() << endl;
        else if (num==4) s.empty() ? cout << 1 << endl : cout << 0 << endl;
        else if (num==5) {
            if (s.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << s.top() << endl;
        }
    }

    return 0;
}