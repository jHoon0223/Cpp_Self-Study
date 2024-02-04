#include <stdio.h>
#include <vector>
#include <queue>

#define MAX 300005
#define INF 99999

using namespace std;

int V,E;

vector<pair<int,int>> Graph[MAX];
int cost[MAX];

void dijkstra(int start) {
    cost[start] = 0;                        //시작점에서 시작점의 거리는 0
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(start,0));            //정점과 정점까지의 거리를 우선순위 큐에 push

    while (!pq.empty()) {
        int current = pq.top().first;       //현재 방문 정점
        int distance = -pq.top().second;    //현재 정점까지의 거리, 음수를 넣어서 가장 작은 수부터 빼도록 설정
        pq.pop();

        if (cost[current] < distance) continue;
        //현재 노드까지의 거리가 저장된 거리보다 크다면 그냥 스킵

        for (int i=0; i<Graph[current].size(); i++) {   //현재 방문한 정점의 주변 정점 모두 조사
            int next = Graph[current][i].first;         //현재 정점을 거쳐서 갈 다음 정점
            int nextDist = distance + Graph[current][i].second;     //현재 정점을 거쳐 다음 정점을 갈때의 거리

            if (nextDist < cost[next]) {    //기존 거리보다 현재 방문 정점을 거친 거리가 더 작다면
                cost[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
                //cost 배열에 저장된 값 갱신 후 pq에 push
            }
        }
    }
}

int main() {
    scanf("%d %d", &V, &E);

    for (int i=1; i<=V; i++) cost[i] = INF;

    int startingPoint;
    scanf("%d", &startingPoint);

    for (int i=0; i<E; i++) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);

        Graph[u].push_back(make_pair(v,w));
    }

    dijkstra(startingPoint);

    for (int i=1; i<=V; i++) {
        if (cost[i] == INF) printf("INF\n");
        else printf("%d\n", cost[i]);
    }

    return 0;
}