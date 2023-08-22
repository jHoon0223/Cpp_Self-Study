#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

char W[8][8] = { 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W' };

char B[8][8] = { 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B',
                 'B','W','B','W','B','W','B','W',
                 'W','B','W','B','W','B','W','B' };

int main() {
    int N, M;
    cin >> N >> M;

    char chess[51][51];
    for (int i=0; i<N; i++) {
        scanf("%s", &chess[i]);
    }

    vector<int> v;

    int total = N*M;
    for (int ii=0; ii<N-7; ii++) {
        for (int jj=0; jj<M-7; jj++) {
            int countW=0, countB=0;
            
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    if (chess[ii+i][jj+j] != W[i][j]) countW++;
                    if (chess[ii+i][jj+j] != B[i][j]) countB++;
                }
            }
            countW < countB ? total=countW : total=countB;
            v.push_back(total);
        }
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;

    return 0;
}