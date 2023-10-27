#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    map<int, int> m;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    int M;
    cin >> M;

    for (int i=0; i<M; i++) {
        int a;
        cin >> a;

        cout << m[a] << ' ';
    }

    return 0;
}