#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N,score,P;

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> N >> score >> P;

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    if (N==P && v.back() >= score) cout << -1 << endl;
    else {
        int rank = 1;
        for (int i=0; i<N; i++) {
            if (v[i] > score) rank++;
            else break;
        }
        cout << rank << endl;
    }

    return 0;
}