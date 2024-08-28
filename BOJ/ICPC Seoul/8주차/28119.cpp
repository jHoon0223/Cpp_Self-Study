#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2005

using namespace std;

int V,E, start;

vector<pair<int,int>> Graph[MAX];
vector<pair<int, pair<int,int>>> Edge;
vector<int> parent;

vector<int> conf;

int getParent(int x) {
    if (parent[x] == x) return x;

    return parent[x] = getParent(parent[x]);
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

    cin >> V >> E >> start;

    for (int i=0; i<E; i++) {
        int u,v,w;
        cin >> u >> v >> w;

        Graph[u].push_back(make_pair(v,w));
        Graph[v].push_back(make_pair(u,w));
    }

    for (int i=0; i<V; i++) {
        int a;
        cin >> a;

        conf.push_back(a);
    }
    //  input Fin.

    for (int u=1; u<=V; u++) {
        for (int j=0; j<Graph[u].size(); j++) {
            int v = Graph[u][j].first;
            int cost = Graph[u][j].second;

            if (u<v) {
                Edge.push_back(make_pair(cost, make_pair(u,v)));
            }
        }
    }

    sort(Edge.begin(), Edge.end());

    parent.resize(V+1);
    for (int i=1; i<=V; i++)
        parent[i] = i;

    int total = 0;
    vector<pair<int,int>> MST;
    for (int i=0; i<Edge.size(); i++) {
        int cost = Edge[i].first;
        int u = Edge[i].second.first;
        int v = Edge[i].second.second;

        if (!find(u,v)) {
            total += cost;
            MST.push_back(make_pair(u,v));
            unionParent(u,v);
        }
    }

    cout << total << '\n';

    return 0;
}