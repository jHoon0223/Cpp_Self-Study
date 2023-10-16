#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(pair<int, int>(a, i));
    }
    sort(A.begin(), A.end());
    
    int P[50];
    for (int i = 0; i < N; i++) {
        P[A[i].second] = i;
    }

    for (int i = 0; i < A.size(); i++)
        cout << P[i] << " ";

    return 0;
}