#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001

using namespace std;

int V,E;

vector<pair<int,int>> Graph[MAX];
vector<pair<int, pair<int,int>>> Edge;
vector<int> parent;
vector<int> ans;

int getParent(int x) {
    if (x == parent[x]) return x;

    return getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a<b) parent[b] = a;
    else parent[a] = b;
}

bool find(int a, int b) {
    return getParent(a) == getParent(b);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    while (1) {
        cin >> V >> E;

        if (V==0 && E==0) break;

        int sum = 0;
        for (int i=0; i<E; i++) {
            int x,y,z;
            cin >> x >> y >> z;

            Graph[x].push_back(make_pair(y,z));
            Graph[y].push_back(make_pair(x,z));

            sum += z;
        }

        for (int u=0; u<V; u++) {
            for (int j=0; j<Graph[u].size(); j++) {
                int v = Graph[u][j].first;
                int cost = Graph[u][j].second;

                if (u<v) Edge.push_back(make_pair(cost, make_pair(u,v)));
            }
        }

        sort(Edge.begin(), Edge.end());

        parent.resize(V);
        for (int i=0; i<V; i++)
            parent[i] = i;
        
        int total=0;
        for (int i=0; i<Edge.size(); i++) {
            int cost = Edge[i].first;
            int u = Edge[i].second.first;
            int v = Edge[i].second.second;

            if (!find(u,v)) {
                total += cost;

                unionParent(u,v);
            }
        }

        ans.push_back(sum - total);

        for (int i=0; i<V; i++) Graph[i].clear();
        Edge.clear();
        parent.clear();
    }

    for (int a : ans) cout << a << '\n';

    return 0;
}