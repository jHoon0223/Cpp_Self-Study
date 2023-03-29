#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int N,M;
    cin >> N >> M;

    vector<int> v;
    for (int i=1; i<=N; i++) v.push_back(i);
    //vector 구성

    while(M-->0) {
        int i, j;
        cin >> i >> j;

        i--; j--;

        swap(v[i], v[j]);
    }

    for (int i=0; i<N; i++) cout << v[i] << ' ';
    cout << '\n';

    return 0;
}