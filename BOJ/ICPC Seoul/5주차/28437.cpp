#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N,Q;
int DP[MAX] = { 0 };

vector<int> total;

void SOL() {
    for(int i=1; i<=50000; i++){
        for(int j=2; i*j<=100000; j++){
            DP[i*j] += DP[i];
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;
    for (int i=1; i<=N; i++) {
        int target;
        cin >> target;
        DP[target] = 1;
    }

    SOL();

    cin >> Q;
    for (int i=1; i<=Q; i++) { 
        int target;
        cin >> target;

        total.push_back(DP[target]);
    }
    
    for (int ans : total) cout << ans << ' ';
    cout << '\n';

    return 0;
}