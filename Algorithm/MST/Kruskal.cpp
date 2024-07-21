#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100; // 최대 정점 수 (필요에 따라 조정 가능)

vector<pair<int, int>> Graph[MAX]; // 전역 변수로 선언된 그래프
vector<int> parent; // 전역 변수로 선언된 유니온 파인드 부모 배열

// 부모 노드를 가져옴 
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 부모 노드를 병합 
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인
bool find(int a, int b) {
    return getParent(a) == getParent(b);
}

int main(void) {
    int n = 7; // 정점의 수
    int m = 11; // 간선의 수
    
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

    // 간선 리스트 생성
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < Graph[u].size(); j++) {
            int v = Graph[u][j].first;
            int cost = Graph[u][j].second;
            if (u < v) { // 중복 간선 방지
                edges.push_back(make_pair(cost, make_pair(u, v)));
            }
        }
    }

    // 간선의 비용으로 오름차순 정렬 
    sort(edges.begin(), edges.end());

    // 유니온 파인드 자료구조 초기화
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // 크루스칼 알고리즘 적용
    int sum = 0;
    vector<pair<int, int>> mst;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        
        if (!find(u, v)) {
            sum += cost;
            mst.push_back(make_pair(u, v));
            unionParent(u, v);
        }
    }

    // MST의 총 가중치 출력
    cout << "MST의 총 가중치: " << sum << '\n';
    cout << "MST의 간선들:" << endl;
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].first << " - " << mst[i].second << '\n';
    }

    return 0;
}