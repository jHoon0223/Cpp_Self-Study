#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    deque<int> dq;
    while(N-->0) {
        int n;
        cin >> n;

        if (n==1) {
            int a;
            cin >> a;
            dq.push_front(a);
        }
        else if (n==2) {
            int a;
            cin >> a;
            dq.push_back(a);
        }
        else if (n==3) {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (n==4) {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (n==5) cout << dq.size() << '\n';
        else if (n==6) dq.empty() ? cout << "1\n" : cout << "0\n";
        else if (n==7) {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if (n==8) {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }

    return 0;
}