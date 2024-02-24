#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    queue<int> Q;
    for (int i=1; i<=N; i++) {
        Q.push(i);
    }

    vector<int> total;
    while (!Q.empty()) {
        for (int i=0; i<K-1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
        total.push_back(Q.front());
        Q.pop();
    }

    cout << "<" << total[0];
    for (int i=1; i<total.size(); i++) {
        cout << ", " << total[i];
    }
    cout << ">\n";

    return 0;
}