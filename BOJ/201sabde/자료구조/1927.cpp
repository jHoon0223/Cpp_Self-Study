#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<int> pq;
    while (N--) {
        int a;
        cin >> a;

        if (a==0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(-a);
        }
    }

    return 0;
}