#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int C;
        cin >> C;
        v.push_back(C);
    }

    for (int i=0; i<N; i++) {
        int Q=0, D=0, N=0, P=0;
        int target = v[i];
        
        Q = target / 25;
        target %= 25;

        D = target / 10;
        target %= 10;
        
        N = target / 5;
        target %= 5;

        P = target;

        cout << Q << ' ' << D << ' ' << N << ' ' << P << endl;
    }

    return 0;
}