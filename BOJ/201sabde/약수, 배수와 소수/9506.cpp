#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    while (1) {
        int N;
        cin >> N;

        if (N==-1) break;

        int sum = 0;
        vector<int> v;
        for (int i=1; i<N; i++) {
            if (N % i == 0) { 
                sum += i;
                v.push_back(i);
            }
        }

        if (sum == N) {
            cout << N << " = ";
            for (int i=0; i<v.size(); i++) {
                if (i == v.size()-1) cout << v[i] << '\n';
                else cout << v[i] << " + ";
            }
        }
        else cout << N << " is NOT perfect.\n";
    }

    return 0;
}