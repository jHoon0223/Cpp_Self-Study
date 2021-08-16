#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int cnt = 0;
    while (N-- > 0) {
        int d = v.back();
        
        if (K >= d) {            
            cnt += K/d;
            K %= d;
        }
        v.pop_back();
    }

    cout << cnt;

    return 0;
}