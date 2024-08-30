#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 60
#define INF 999999

using namespace std;

int N, total = 0;
int capacity[MAX][MAX], flow[MAX][MAX], visited[MAX];
    // 용량              유량             이전에 방문 여부

vector<int> V[MAX];

// 정점 문자를 0~51 사이의 번호로 바꿔주는 간단한 함수
int CtoI(char c){
    if(c <= 'Z') return c - 'A';

    return c - 'a' + 26;
}

void maxFlow(int start, int end) {
    while (1) {
        fill(visited, visited+MAX, -1);

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : V[curr]) {
                // c[i][j]-f[i][j] > 0: i에서 j로 유량을 흘릴 여유가 남았는가?
                // visited[next] == -1: next 정점을 아직 방문하지 않았는가?
                if (capacity[curr][next] - flow[curr][next] > 0 && visited[next] == -1) {
                    q.push(next);
                    visited[next] = curr;    // 경로를 기억하기 위해 visited 배열 사용

                    if (next == end) break;  // 싱크에 도달하면 탈출
                }
            }
        }
        //  BFS로 찾음

        if (visited[end] == -1) break;
        // 싱크로 가는 경로가 더 없으면 루프 탈출

        // 경로상에서 가장 허용치가 낮은 곳을 찾음
        int tmp = INF;
        for (int i=end; i!=start; i=visited[i])
            tmp = min(tmp, capacity[visited[i]][i] - flow[visited[i]][i]);

        for (int i=end; i!=start; i=visited[i]) {
            flow[visited[i]][i] += tmp;
            flow[i][visited[i]] -= tmp;
        }   // 찾은 flow만큼 해당 경로에 유량 흘려줌

        total += tmp;   // 총 유량 값 증가
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;

    while (N-->0) {
        char u,v;
        int w;
        cin >> u >> v >> w;
        int from = CtoI(u), to = CtoI(v);

        V[from].push_back(to);
        V[to].push_back(from);
        capacity[from][to] += w;
        capacity[to][from] += w;
    }
    //  input Fin.

    //  소스부터 싱크까지 최대 유량 계산
    maxFlow(CtoI('A'),CtoI('Z'));

    cout << total << '\n';

    return 0;
}