#include <iostream>

#define MAX 101

using namespace std;

int N;
int Graph[MAX][MAX];

void FloydWarshall() {
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (Graph[i][k] != 0 && Graph[k][j] != 0) {
                    Graph[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a;
            cin >> a;
            Graph[i][j] = a;
        }
    }

    FloydWarshall();

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << Graph[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}