#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;
    for (int i=0; i<9; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int sum=0;
    for (int i=0; i<9; i++)
        sum += v[i];

    sum -= 100;

    int i=0, j=8;
    int newSum=0;
    while(1) {
        newSum = v[i]+v[j];

        if (sum == newSum) break;
        
        if (newSum < sum) i++;
        else if (newSum > sum) j--;
    }

    v.erase(v.begin() + i);
    v.erase(v.begin() + --j);

    for (int i=0; i<7; i++) 
        printf("%d\n", v[i]);

    return 0;
}