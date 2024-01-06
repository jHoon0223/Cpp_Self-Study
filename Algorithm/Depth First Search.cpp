#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

void DFS(int start) {
	visited[start] = true;

	cout << start << " ";

	for (int i=0; i<graph[start].size(); i++) { //인접한 정점의 갯수만큼 탐색
		int idx = graph[start][i];

		if (!visited[idx]) //해당 정점이 아직 방문한적이 없는 정점이면 재귀적으로 DFS 실행
            DFS(idx);
	}
}

int main(void) {
    graph[1].push_back(2);
    graph[1].push_back(5);

    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[2].push_back(5);

    graph[3].push_back(4);
    graph[3].push_back(7);

    graph[4].push_back(2);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[4].push_back(6);
    graph[4].push_back(8);

    graph[5].push_back(1);
    graph[5].push_back(2);
    graph[5].push_back(4);
    graph[5].push_back(8);

    graph[6].push_back(4);
    graph[6].push_back(7);
    graph[6].push_back(8);

    graph[7].push_back(3);
    graph[7].push_back(6);

    graph[8].push_back(4);
    graph[8].push_back(5);
    graph[8].push_back(6);
    //vector 배열로 그래프 정의

    DFS(1);

    return 0;
}