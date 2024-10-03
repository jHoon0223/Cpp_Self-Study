#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define MAX 401
#define INF 99999999

using namespace std;

int V,E;
int arr[MAX][MAX];

void floydWarshall() {
    for (int k=0; k<V; k++) {
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (arr[i][k] != INF && arr[k][j] != INF)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> V >> E;

    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            arr[i][j] = INF;
        }
    }

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        arr[a][b] = c;
    }

    floydWarshall();

    // set<int> total;
    // for (int i=0; i<V; i++) {
    //     for (int j=0; j<V; j++) {
    //         if (i==j && arr[i][j] != INF) {
    //             total.insert(arr[i][j]);
    //         }
    //     }
    // }

    // if (total.empty()) cout << -1 << '\n';
    // else cout << *total.begin() << '\n';

    vector<int> total;
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            if (i==j && arr[i][j] != INF) {
                total.push_back(arr[i][j]);
            }
        }
    }

    if (total.empty()) cout << -1 << '\n';
    else {
        sort(total.begin(), total.end());
        cout << total.front() << '\n';
    }

    return 0;
}