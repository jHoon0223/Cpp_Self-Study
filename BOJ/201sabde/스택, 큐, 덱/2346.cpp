#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    deque<pair<int, int>> dq;

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        dq.push_back(make_pair(i+1, a));
    }

    while(1) {
        cout << dq.front().first << ' ';
        int k = dq.front().second;
        dq.pop_front();

        if (dq.empty()) return 0;
        
        if (k>0) {
            for (int i=0; i<k-1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int i=0; i<(-1*k); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}