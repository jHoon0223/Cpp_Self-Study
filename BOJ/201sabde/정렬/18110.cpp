#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    if (n==0) {
        printf("0\n");
        return 0;
    }

    vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int num = round((double)n*0.15);

    double sum=0;
    for (int i=num; i<n-num; i++)
        sum += v[i];

    int total = round(sum / (n - num*2));
    printf("%d\n", total);

    return 0;
}