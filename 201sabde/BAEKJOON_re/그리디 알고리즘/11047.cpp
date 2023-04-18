#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int cnt=0;
    for (int i=N-1; i>=0; i--) {
        if (K % v[i] < K) {
            cnt += K / v[i];
            K = K % v[i];
        }
    }

    cout << cnt << endl;

    return 0;
}