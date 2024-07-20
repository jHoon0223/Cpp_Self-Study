#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100; // 최대 정점 수 (필요에 따라 조정 가능)
const int INF = 999999; // 무한대를 표현하기 위한 값

int n = 7; // 정점의 수
int m = 11; // 간선의 수

vector<pair<int, int>> Graph[MAX]; // 전역 변수로 선언된 그래프

vector<int> minEdge(n, INF); // 각 정점으로의 최소 간선 가중치
vector<bool> selected(n, false); // 각 정점의 선택 여부

// 프림 알고리즘을 사용하여 MST를 구하는 함수
int prim(int start) {
    minEdge[start] = 0;
    int sum = 0; // MST의 총 가중치

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start)); // (가중치, 목적지) 형태로 우선순위 큐에 삽입

    while (!pq.empty()) {
        int weight = -pq.top().first; // 음수로 저장했으므로, 다시 양수로 변환
        int u = pq.top().second;
        pq.pop();

        if (selected[u]) continue;
        selected[u] = true;
        sum += weight;

        for (int i = 0; i < Graph[u].size(); i++) {
            int v = Graph[u][i].first;
            int cost = Graph[u][i].second;

            if (!selected[v] && cost < minEdge[v]) {
                minEdge[v] = cost;
                pq.push(make_pair(-cost, v)); // 음수로 변환하여 삽입
            }
        }
    }

    return sum;
}

int main(void) {    
    // 간선 정보 입력 (정점 번호는 0부터 시작)
    Graph[0].push_back(make_pair(6, 12));
    Graph[6].push_back(make_pair(0, 12));

    Graph[0].push_back(make_pair(3, 28));
    Graph[3].push_back(make_pair(0, 28));

    Graph[0].push_back(make_pair(1, 67));
    Graph[1].push_back(make_pair(0, 67));

    Graph[0].push_back(make_pair(4, 17));
    Graph[4].push_back(make_pair(0, 17));

    Graph[1].push_back(make_pair(3, 24));
    Graph[3].push_back(make_pair(1, 24));

    Graph[1].push_back(make_pair(4, 62));
    Graph[4].push_back(make_pair(1, 62));

    Graph[2].push_back(make_pair(4, 20));
    Graph[4].push_back(make_pair(2, 20));

    Graph[2].push_back(make_pair(5, 37));
    Graph[5].push_back(make_pair(2, 37));

    Graph[3].push_back(make_pair(6, 13));
    Graph[6].push_back(make_pair(3, 13));

    Graph[4].push_back(make_pair(5, 45));
    Graph[5].push_back(make_pair(4, 45));

    Graph[4].push_back(make_pair(6, 73));
    Graph[6].push_back(make_pair(4, 73));

    // 프림 알고리즘을 사용하여 MST의 총 가중치를 계산
    int mstWeight = prim(0); // 0번 정점에서 시작
    
    cout << "MST의 총 가중치: " << mstWeight << '\n';

    return 0;
}