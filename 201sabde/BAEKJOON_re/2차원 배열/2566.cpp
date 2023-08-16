#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> A;
    vector<int> B;

    for (int i=0; i<81; i++) {
        int a;
        cin >> a;
        A.push_back(a);
        B.push_back(a);
    }
    sort(A.begin(), A.end());

    int MAX = A.back(); //행렬의 최댓값

    int index = find(B.begin(), B.end(), MAX) - B.begin()+1;

    int col, row;
    col = index%9;
    row = index/9 + 1;

    if (col == 0) {
        row--;
        col = 9;
    }

    cout << MAX << endl;
    cout << row << ' ' << col << endl;

    return 0;
}