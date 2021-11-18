#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());
    
    float total = 0, M = v1.back();
    for (int i = 0; i < N; i++) {
        float temp = (v1[i]/M)*100;
        total += temp;
    }
    cout << total/N;

    return 0;
}