#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    set<string> s;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }

    set<string>::iterator it;
    int cnt=0;
    for (int i=0; i<M; i++) {
        string str;
        cin >> str;

        it = s.find(str);
        if (it != s.end()) cnt++;
        else continue;
    }
    cout << cnt << endl;

    return 0;
}