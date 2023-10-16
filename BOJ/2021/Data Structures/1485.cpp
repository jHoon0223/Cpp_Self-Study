#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <functional>

using namespace std;

int D(pair<int, int> x, pair<int, int> y) {
    return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}

int main() {
    int N;
    cin >> N;

    while(N-->0) {
        bool tf = true;
        vector<pair<int, int>> v(5);

        for (int i = 0; i < 4; i++)
            cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.begin()+4);
        sort(v.begin()+2, v.begin()+4, greater<pair<int, int>>());

        int d = D(v[3], v[0]);
        for (int i = 1; i < 4; i++) {
            if (d != D(v[i-1], v[i])); {
                tf = false;
                break;
            }
        }
        if (tf && D(v[2], v[0]) != D(v[3], v[1]))
            tf = false;

        tf ? cout << "1\n" : cout << "0\n";
    }

    return 0;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int, int>> board(5);
        bool flag = true;

        for(int i=0; i<4; i++)
            cin >> board[i].first >> board[i].second;
        sort(board.begin(), board.begin()+4);
        sort(board.begin()+2, board.begin()+4, greater<pair<int, int>>());

        int len = dist(board[3], board[0]);
        for(int i=1; i<4; i++){
            if(len != dist(board[i-1], board[i])){
                flag = false;
                break;
            }
        }
        
        if(flag && dist(board[2], board[0]) != dist(board[3], board[1])) flag = false;

        (flag) ? cout << "1\n" : cout << "0\n";

    }
    return 0;
}*/