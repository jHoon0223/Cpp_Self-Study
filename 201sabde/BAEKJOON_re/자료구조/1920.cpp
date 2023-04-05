#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool binary_search(vector<int>& v, int len, int target) {
    int left=0, right=len-1;

    while(left <= right) {
        int mid = (left+right) / 2;

        if (target == v[mid]) return true;

        if (target < v[mid]) right = mid-1;
        else if (target > v[mid]) left = mid+1;
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    int M;
    cin >> M;
    while(M-->0) {
        int n;
        cin >> n;

        binary_search(A, A.size(), n) ? printf("1\n") : printf("0\n");
    }

    return 0;
}