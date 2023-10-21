#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int A[101][101];
    int B[101][101];

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int a;
            cin >> a;
            A[i][j] = a;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int a;
            cin >> a;
            B[i][j] = a;
        }
    }
    //행렬 A와 B입력

    int C[101][101];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}