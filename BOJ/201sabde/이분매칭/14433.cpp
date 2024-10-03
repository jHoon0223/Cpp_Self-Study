#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 301

using namespace std;

int N,M,K1,K2;
int matched[MAX];
bool visited[MAX];
vector<int> V1[MAX], V2[MAX];

bool DFS(vector<int> v[], int curr) {
    for (int next : v[curr]) {
        if (visited[next]) continue;

        visited[next] = true;

        if (!matched[next] || DFS(v, matched[next])) {
            matched[next] = curr;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M >> K1 >> K2;

    int a,b;
    for (int i=0; i<K1; i++) {
        cin >> a >> b;
        V1[a].push_back(b);
    }
    for (int i=0; i<K2; i++) {
        cin >> a >> b;
        V2[a].push_back(b);
    }

    int total1=0, total2=0;
    for (int target=1; target<=N; target++) {
        fill(visited, visited+MAX, false);
        if (DFS(V1, target)) total1++;
    }
    fill(matched, matched+MAX, 0);
    for (int target=1; target<=N; target++) {
        fill(visited, visited+MAX, false);
        if (DFS(V2, target)) total2++;
    }

    total1 < total2 ? cout << "네 다음 힐딱이\n" : cout << "그만 알아보자\n";

    return 0;
}