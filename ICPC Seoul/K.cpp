#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> G[100001];
priority_queue<int, vector<int>, greater<>> Q;
int indegree[100001];
int N, M, cnt = 0;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        indegree[b]++;
    }

    
    for(int i = 1; i <= N; i++){
        if(!indegree[i]) Q.push(i);
    }
    vector<int> temp;
    
    while(!Q.empty()){
        
        int v = Q.top(); Q.pop(); cnt++;
        temp.push_back(v);
        for(auto i : G[v]) if(!--indegree[i]) Q.push(i);
    }

    if(cnt < N){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i : temp) cout << i << " ";
}