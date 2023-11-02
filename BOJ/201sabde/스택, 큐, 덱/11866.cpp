#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    queue<int> q;
    vector<int> v;

    for (int i=0; i<N; i++) q.push(i+1);

    while(!q.empty()) {
        for(int i=0; i<K-1; i++) {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << '<';
    for (int i=0; i<v.size()-1; i++) cout << v[i] << ", ";
    cout << v.back() << ">\n";

    return 0;
}