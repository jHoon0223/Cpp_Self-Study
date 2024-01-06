#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[9];
vector<int> Graph[9];

// BFS 함수 정의
void BFS(int start) {
    queue<int> q;
    q.push(start); //첫 노드를 queue에 삽입
    visited[start] = true; //첫 노드를 방문 처리

    //큐가 빌 때까지 반복
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        cout << n << ' ';
        //큐에서 하나의 정점을 뽑아 출력

        for (int i = 0; i < Graph[n].size(); i++) {     //인접한 정점의 갯수만큼 탐색
            int idx = Graph[n][i];

            if (!visited[idx]) {        //아직 방문하지 않은 정점일때에만 진행. 방문했던 정점은 무시하고 다른 정점을 찾음
                q.push(idx);
                visited[idx] = true;    //아직 방문하지 않은 정점들을 큐에 삽입 후, 방문 처리
            }
        }
    }
}

int main() {
    Graph[1].push_back(2);
    Graph[1].push_back(5);

    Graph[2].push_back(1);
    Graph[2].push_back(4);
    Graph[2].push_back(5);

    Graph[3].push_back(4);
    Graph[3].push_back(7);

    Graph[4].push_back(2);
    Graph[4].push_back(3);
    Graph[4].push_back(5);
    Graph[4].push_back(6);
    Graph[4].push_back(8);

    Graph[5].push_back(1);
    Graph[5].push_back(2);
    Graph[5].push_back(4);
    Graph[5].push_back(8);

    Graph[6].push_back(4);
    Graph[6].push_back(7);
    Graph[6].push_back(8);

    Graph[7].push_back(3);
    Graph[7].push_back(6);

    Graph[8].push_back(4);
    Graph[8].push_back(5);
    Graph[8].push_back(6);
    //vector 배열로 그래프 정의

    BFS(1);

    return 0;
}