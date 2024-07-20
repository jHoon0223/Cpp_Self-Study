#include <iostream>
#include <vector>
#include <queue>

#define MAX 10001
#define INF 999999
 
using namespace std;
 
int N,M,t;
int total = 0;
 
bool visited[MAX] = { false };
vector<pair<int,int>> Graph[MAX];
priority_queue<pair<int, int> > pq;
 
void prim(int curr, int cnt){
    visited[curr] = true;
    
    // 시작 노드에서 연결된 간선들 중에 가장 비용이 적은 간선 뽑을 준비  
    for(int i=0; i<Graph[curr].size(); i++){
        int next = Graph[curr][i].first;
        int cost = Graph[curr][i].second;
        
        if(visited[next]==false) pq.push(make_pair(-cost,next));
    }
    
    // 비용이 가장 적은 간선 뽑아서 연결하기  
    while(!pq.empty()){
        int next = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(visited[next]) continue;

        total += cost + cnt*t;
        prim(next, cnt+1);

        return;
    }
}
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M >> t;

    for (int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));
    }
    
    prim(1, 0);
    
    cout << total << endl;
}
