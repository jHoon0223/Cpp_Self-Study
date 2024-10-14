#include <iostream>
#include <queue>

#define MAX 22
 
using namespace std;

int Dx[] = {0, -1, 1, 0}; // 상 좌 우 하
int Dy[] = {-1, 0, 0, 1};

int n;
int arr[MAX][MAX];

int shark_x, shark_y, total = 0, cnt = 0, shark = 2;
bool eat = false, flag = false;

void BFS(int a, int b, bool visited[][MAX], int shark){
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    visited[b][a] = true;
    int temp; // 한 마리를 먹는데 걸린 시간

    while(!Q.empty()){
        int x = Q.front().first.first; // 열 좌표
        int y = Q.front().first.second; // 행 좌표
        int cnt = Q.front().second; // 현재 시간

        // 가장 위쪽을 먼저 그 다음 왼쪽을 우선적으로 먹는 것을 고려
        if(arr[y][x] > 0 && arr[y][x] <shark && temp == cnt){
            if((shark_y > y) || (shark_y == y && shark_x > x)){
                shark_y = y; // 물고기를 먹은 상어 위치 저장
                shark_x = x;
                continue;
            }
        }

        Q.pop();

        for (int i = 0; i < 4; i++){
            int newX = x + Dx[i]; // 방향 이동
            int newY = y + Dy[i];
 
            if(newX >= 0 && newX < n && newY >= 0 && newY < n && visited[newY][newX] == false){
                if(arr[newY][newX] <= shark){// 지나가거나 먹을 수 있는 경우
                    if(arr[newY][newX] > 0 && arr[newY][newX] < shark && !eat){ //물고기를 먹을 수 있는 경우
                        eat = true; // 한 마리 먹음
                        shark_x = newX; shark_y = newY;
                        temp = cnt + 1; // 한 마리 먹는데걸린 시간
                        total += temp; // 총 시간에 추가
                    }
                    else{ // 물고기를 못먹는 경우
                        Q.push(make_pair(make_pair(newX, newY), cnt + 1));
                        visited[newY][newX] = true;
                    }                      
                }
            }
        }
    }
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n;j++){
            cin >> arr[i][j];

            if(arr[i][j] == 9){
                shark_y = i; // 상어 시작 위치
                shark_x = j;
                arr[i][j] = 0;
            }
        }
    }
 
    while(!flag){
        bool visited[MAX][MAX] = { false };
        BFS(shark_x, shark_y, visited, shark); // 한 마리 먹을때까지 이동
        
        if(eat){ // 먹었을 경우
            eat = false; 
            cnt++; // 현재 크기에서 물고기 먹은 횟수 증가
            arr[shark_y][shark_x] = 0; // 먹은 물고기 삭제
            
            if(cnt == shark){ // 상어 크기가 증가하는 경우
                shark++; // 상어 사이즈 +1
                cnt = 0; //현재 크기에서 물고기 먹은 횟수 초기화
            }
        }
        else flag = true;
    }

    cout << total << '\n';

    return 0;
}
