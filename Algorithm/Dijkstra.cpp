#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 99999

using namespace std;

int V=8, E=14;

vector<pair<int,int>> Graph[MAX];           //정점과, 정점까지의 거리를 저장한 pair형 vector
int cost[MAX];                              //시작점에서 해당 정점까지의 거리를 저장할 배열

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

        for (pair<int,int> curr : Graph[current]) {     //현재 방문한 정점의 주변 정점 모두 조사
            int next = curr.first;                      //현재 정점을 거쳐서 갈 다음 정점
            int nextDist = distance + curr.second;      //현재 정점을 거쳐 다음 정점을 갈때의 거리

            if (nextDist < cost[next]) {     //기존 거리보다 현재 방문 정점을 거친 거리가 더 작다면
                cost[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
                //cost 배열에 저장된 값 갱신 후 pq에 push
            }
        }
    }
}

int main() {
    for (int i=1; i<=E; i++) cost[i] = INF;
    //일단 cost배열 INF로 초기화

    Graph[1].push_back(make_pair(2,3));
    Graph[1].push_back(make_pair(3,4));

    Graph[2].push_back(make_pair(1,3));
    Graph[2].push_back(make_pair(3,5));
    Graph[2].push_back(make_pair(4,10));
    Graph[2].push_back(make_pair(6,9));

    Graph[3].push_back(make_pair(1,4));
    Graph[3].push_back(make_pair(2,5));
    Graph[3].push_back(make_pair(4,8));
    Graph[3].push_back(make_pair(5,5));
    
    Graph[4].push_back(make_pair(2,10));
    Graph[4].push_back(make_pair(3,8));
    Graph[4].push_back(make_pair(5,6));
    Graph[4].push_back(make_pair(6,10));
    Graph[4].push_back(make_pair(7,7));
    Graph[4].push_back(make_pair(8,3));

    Graph[5].push_back(make_pair(3,5));
    Graph[5].push_back(make_pair(4,6));
    Graph[5].push_back(make_pair(7,4));

    Graph[6].push_back(make_pair(2,9));
    Graph[6].push_back(make_pair(4,10));
    Graph[6].push_back(make_pair(8,2));

    Graph[7].push_back(make_pair(4,7));
    Graph[7].push_back(make_pair(5,4));
    Graph[7].push_back(make_pair(8,5));

    Graph[8].push_back(make_pair(4,3));
    Graph[8].push_back(make_pair(6,2));
    Graph[8].push_back(make_pair(7,5));
    //그래프 생성. vector배열 이용하여 선언, first인자는 목적지, second인자는 목적지 까지의 거리

    int startingPoint;
    cout << "시작 지점을 입력하세요 >> ";
    cin >> startingPoint;
    dijkstra(startingPoint);

    for (int i=1; i<=V; i++) {
        cout << "시작점 " << startingPoint << " ~ " << i << " 까지의 최단 거리 >> " << cost[i] << endl;
    }

    return 0;
}