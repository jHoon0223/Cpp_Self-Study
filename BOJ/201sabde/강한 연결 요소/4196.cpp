#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

#define MAX 100002

using namespace std;

vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> st;

int visited_num;
int visited[MAX];
int scc_cnt;
int node_SCC[MAX];
int DP[MAX];

int DFS(int curr) {
    visited[curr] = visited_num;
    visited_num++;
    st.push(curr);
    int val = visited[curr];
    
    for (int next : v[curr]) {
        if (visited[next] == -1) val = min(val, DFS(next));
        else if (node_SCC[next] == -1) val = min(val, visited[next]);
    }

    if (val == visited[curr]) {
        vector<int> tmp;

        while (1) {
            int target = st.top();
            st.pop();
            node_SCC[target] = scc_cnt;
            tmp.push_back(target);

            if (target == curr) break;
        }
        SCC.push_back(tmp);
        scc_cnt++;
    }

    return val;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T-->0) {
        scc_cnt = 0;
        visited_num = 0;

        fill(visited, visited+MAX, -1);
        fill(node_SCC, node_SCC+MAX, -1);
        fill(DP, DP+MAX, 0);

        for (int i=0; i<MAX; i++) v[i].clear();
        SCC.clear();

        int N,M;
        cin >> N >> M;        

        for (int i=0; i<M; i++) {
            int a,b;
            cin >> a >> b;

            v[a].push_back(b);
        }

        for (int target=1; target<=N; target++)
            if (visited[target] == -1) DFS(target);

        set<int> scc_set[MAX];
        for (int curr=1; curr<=N; curr++) {
            for (int next : v[curr]) {
                if (node_SCC[next] != node_SCC[curr])
                    scc_set[node_SCC[curr]].insert(node_SCC[next]);
            }
        }

        int total = 0;
        for (int i=scc_cnt-1; i>=0; i--) {
            if (DP[i] == 0) total++;
            
            for (int next : scc_set[i]) DP[next] = 1;
        }
        cout << total << '\n';
    }

    return 0;
}