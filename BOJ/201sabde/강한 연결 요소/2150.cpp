#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define MAX 10005

using namespace std;

int V,E;

int visited_num;
int visited[MAX];
int node_SCC[MAX];
int SCC_cnt;
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> st;

int DFS(int curr) {
    visited[curr] = visited_num;
    visited_num++;
    st.push(curr);
    int val = visited[curr];

    for (int next : v[curr]) {
        if (visited[next] == -1) 
            val = min(val, DFS(next));
        else if (node_SCC[next] == -1) 
            val = min(val, visited[next]);  // Back Edge
    }

    if (val == visited[curr]) {
        vector<int> ret;

        while (1) {
            int target = st.top();
            st.pop();
            node_SCC[target] = SCC_cnt;
            ret.push_back(target);

            if (target == curr) break;
        }
        sort(ret.begin(), ret.end());
        SCC.push_back(ret);
        SCC_cnt++;
    }

    return val;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    fill(visited, visited+MAX, -1);
    fill(node_SCC, node_SCC+MAX, -1);

    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    // input Fin.

    for (int i=1; i<=V; i++) 
        if (visited[i] == -1) DFS(i);

    sort(SCC.begin(), SCC.end());
    cout << SCC.size() << '\n';

    for (vector<int> _scc : SCC) {
        for (int ans : _scc) cout << ans << ' ';
        cout << "-1\n";
    }

    return 0;
}