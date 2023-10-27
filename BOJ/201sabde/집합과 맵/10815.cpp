#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    set<int> s;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    int M;
    cin >> M;

    set<int>::iterator it;
    for (int i=0; i<M; i++) {
        int a;
        cin >> a;

        it = s.find(a);
        if (it != s.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    printf("\n");

    return 0;
}