#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    while (N-->0) {
        int a;
        cin >> a;

        if (a==0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            } 
        }
        else {
            pq.push(make_pair(abs(a), a));
        }
    }

    return 0;
}