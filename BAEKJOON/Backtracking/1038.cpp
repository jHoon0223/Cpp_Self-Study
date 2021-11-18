#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void FF(int N);

vector<long long> v;
queue<long long> q;

int main() {
    cin.tie(NULL), cout.tie(NULL), ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    v.resize(N+1, 0);

    for (int i = 1; i < 10; i++)
        q.push(i);

    FF(N);
    
    if (v[N] || N == 0)
        cout << v[N];
    else
        cout << -1;

    return 0;
}

void FF(int N) {
    int idx = 1;

    while (!q.empty() && N) {
        long long target = q.front();
        q.pop();
        N--;

        v[idx++] = target;

        int tmp = target % 10;
        int addNum = 0;
        while (addNum < tmp) {
            q.push(target*10 + addNum++);
        }
    }
}