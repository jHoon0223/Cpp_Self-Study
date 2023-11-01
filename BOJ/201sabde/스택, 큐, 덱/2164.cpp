#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    queue<int> q;

    for (int i=1; i<=N; i++) q.push(i);

    while(1) {
        if (q.size() == 1) break;
        q.pop();

        if (q.size() == 1) break;
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << '\n';

    return 0;
}