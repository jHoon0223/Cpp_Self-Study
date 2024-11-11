#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 100005

using namespace std;;

int N,M;

int val[MAX];
vector<int> child[MAX];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> N >> M;

    fill(val, val+MAX, 0);

    for (int i=1; i<=N; i++) {
        int a;
        cin >> a;

        if (a == -1) continue;
        
        child[a].push_back(i);
    }

    queue<int> q;
    for (int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b;

        if (a == 1) {
            cin >> c;

            val[b] += c;
            
            q.push(b);

            while (!q.empty()) {
                int target = q.front();
                q.pop();

                for (int _c : child[target]) {
                    val[_c] += c;
                    
                    q.push(_c);
                }
            }
        }
        else if (a == 2) cout << val[b] << '\n';
    }

    return 0;
}