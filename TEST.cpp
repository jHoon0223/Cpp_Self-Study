#include <iostream>
#include <queue>

using namespace std;

int picture[501][501];
int visited[501][501];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int areaCnt, maxArea;
int n,m;

int bfs(int i, int j){
    queue <pair<int,int>> q;
    visited[i][j] = 1;
    q.push({i,j});
    int area = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if ((newX>=0 && newX<m) && (newY>=0 && newY<n) &&
            (visited[newX][newY] == false)) {
                if (picture[newX][newY] == 1) {
                    q.push(make_pair(newX,newY));
                    visited[newX][newY] = true;
                    area++;
                }
            }
        }
    }
    return area;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> picture[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && picture[i][j]){
                areaCnt++;
                maxArea = max(maxArea,bfs(i,j));
            }
        }
    }

    cout << areaCnt << '\n';
    cout << maxArea << '\n';
}