#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    int tmp;
    for(int i=0; i<n*n; i++) {
        cin >> tmp;
        pq.push(tmp);

        if(pq.size() > n) pq.pop();
    }

    cout << pq.top() << '\n';


    return 0;
}