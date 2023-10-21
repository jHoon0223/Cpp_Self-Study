#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int M = v.back();
    double sum = 0;

    for (int i=0; i<N; i++) {
        sum += (double)v[i] / (double)M * 100.0;
    }
    printf("%f\n", sum/(double)N);

    return 0;
}