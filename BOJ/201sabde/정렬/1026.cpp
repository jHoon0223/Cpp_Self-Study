#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A,B;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        A.push_back(a);
    }

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        B.push_back(a);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    
    int total=0;
    for (int i=0; i<N; i++) {
        total += (A[i] * B[i]);
    }
    cout << total << '\n';
    
    return 0;
}