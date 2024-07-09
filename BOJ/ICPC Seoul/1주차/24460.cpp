#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1025

using namespace std;

int N;
int arr[MAX][MAX];

int F(int x, int y, int n) {
    vector<int> v;

    if (n==1) return arr[x][y];

    int left_up = F(x, y, n/2);
    int left_down = F(x + n/2, y, n/2);
    int right_up = F(x, y + n/2, n/2);
    int right_down = F(x + n/2, y + n/2, n/2);

    v.push_back(left_up);
    v.push_back(left_down);
    v.push_back(right_up);
    v.push_back(right_down);

    sort(v.begin(), v.end());

    return v[1];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << F(0, 0, N) << '\n';

    return 0;
}