#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    queue<int> q;
    while(N-->0) { 
        string s;
        cin >> s;

        if (!s.compare("push")) {
            int a;
            cin >> a;

            q.push(a);
        }
        else if (!s.compare("pop")) {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (!s.compare("size")) cout << q.size() << '\n';
        else if (!s.compare("empty")) q.empty() ? cout << 1 << '\n' : cout << 0 << '\n';
        else if (!s.compare("front")) {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (!s.compare("back")) {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}