#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 2004

using namespace std;

int N,M;
int visited[MAX], node_scc[MAX], visited_num, scc_num;
vector<int> graph[MAX];
stack<int> st;

inline int nX(int a) { return a ^ 1; }
inline int tX(int a) { return a * 2 - 2; }
inline int fX(int a) { return a * 2 - 1; }

int DFS(int curr) {
    visited[curr] = visited_num;
    visited_num++;
    st.push(curr);
    int val = visited[curr];

    for (int next : graph[curr]) {
        if (visited[next] == -1) val = min(val, DFS(next));
        else if (node_scc[next] == -1) val = min(val, visited[next]);
    }

    if (val == visited[curr]) {
        while (1) {
            int target = st.top();
            st.pop();
            node_scc[target] = scc_num;
            
            if (target == curr) break;
        }
        scc_num++;
    }

    return val;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    while (cin >> N >> M) {
        for (int i=0; i<MAX; i++) graph[i].clear();
        visited_num = 0; scc_num = 0;
        fill(visited, visited+MAX, -1);
        fill(node_scc, node_scc+MAX, -1);

        graph[fX(1)].push_back(tX(1));
        for (int i=0; i<M; i++) {
            int u,v;
            cin >> u >> v;

            u = u > 0 ? tX(u) : fX(-u);
            v = v > 0 ? tX(v) : fX(-v);

            graph[nX(u)].push_back(v);
            graph[nX(v)].push_back(u);
        }
        
        for (int i=0; i<=2*N-1; i++) 
            if (visited[i] == -1) DFS(i);

        bool flag = true;
        for (int i=1; i<=N; i++) {
            if (node_scc[tX(i)] == node_scc[fX(i)]) {
                flag = false;
                break;
            }
        }
        flag ? cout << "yes\n" : cout << "no\n";
    }

    return 0;
}