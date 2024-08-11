#include <iostream>
#include <vector>

#define MAX 100005

using namespace std;

vector<long long> V,E;
int flag[MAX] = { false };

long long total = 0;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=0; i<N-1; i++) {
        int a;
        cin >> a;
        E.push_back(a);
    }

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }

    for (int idx=0; idx<N-1; idx++) {
        if (flag[idx]) continue;

        if (V[idx] >= V[idx+1]) {
            total += V[idx] * E[idx];
        }
        else {
            total += V[idx] * E[idx];

            for (int j=idx+1; j<N-1; j++) {
                if (V[idx] < V[j]) {
                    total += V[idx] * E[j];
                    
                    flag[j] = true;
                }
                else break;
            }
        }
    }

    cout << total << '\n';

    return 0;
}