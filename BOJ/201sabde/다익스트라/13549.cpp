#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N,K;
int visited[MAX][2];
//[0]엔 방문 여부 / [1]엔 시간 저장

struct cmp{
    bool operator()(int n1,int n2){
        if(visited[n1][1]>visited[n2][1]){
            return true;
        }//시간에 따라 우선순위 부여
        else{
            return false;
        }
    }
};

priority_queue<int,vector<int>,cmp> Q;

int F(int a, int c) {
    visited[a][0] = 1;
    visited[a][1] = 0;
    Q.push(a);

    while (!Q.empty()) {
        int n = Q.top();
        int cnt = visited[n][1];
        Q.pop();

        if (n == K) return cnt;

        if (n*2>=0 && n*2<MAX) {
            if (!visited[n*2][0] || visited[2*n][1] > cnt) {
                visited[2*n][0] = 1;
                visited[2*n][1] = cnt;
                Q.push(2*n);
            }
        }

        if (n+1>=0 && n+1<MAX) {
            if (!visited[n+1][0] || visited[n+1][1] > cnt+1) {
                visited[n+1][0] = 1;
                visited[n+1][1] = cnt+1;
                Q.push(n+1);
            }
        }

        if (n-1>=0 && n-1<MAX) {
            if (!visited[n-1][0] || visited[n-1][1] > cnt+1) {
                visited[n-1][0] = 1;
                visited[n-1][1] = cnt+1;
                Q.push(n-1);
            }
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> N >> K;

    cout << F(N,0) << '\n';

    return 0;
}