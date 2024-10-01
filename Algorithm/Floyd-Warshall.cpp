#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대를 표현하기 위한 값
const int MAX_V = 100; // 최대 정점 수 (필요에 따라 변경)
int dist[MAX_V][MAX_V];  // 전역 변수로 최단 경로 배열 선언
int V; // 정점의 수

// 플로이드 워셜 알고리즘 함수
void floydWarshall() {
    // 플로이드-워셜 알고리즘 수행
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "정점의 수 입력: ";
    cin >> V;

    // dist 배열 초기화 (자기 자신으로 가는 거리는 0, 그 외에는 INF로 초기화)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // 인접 리스트 입력 받기
    int E; // 간선의 수
    cout << "간선의 수 입력: ";
    cin >> E;

    cout << "간선 입력 (형식: u v w) - u에서 v로 가는 가중치 w:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // 인접 리스트를 인접 행렬로 변환
    }

    // 플로이드-워셜 알고리즘 실행
    floydWarshall();

    return 0;
}