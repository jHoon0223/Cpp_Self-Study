#include <iostream>
#include <vector>

using namespace std;

vector<int> v(6);

int ansT=0;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=0; i<6; i++) {
        int a;
        cin >> a;

        v.push_back(a);
    }

    int T,P;
    cin >> T >> P;

    for (int target : v) {
        if (target%T == 0) ansT += target/T;
        else ansT += target / T + 1;
    }

    cout << ansT << '\n';
    cout << N/P << ' ' << N%P << '\n';

    return 0;
}