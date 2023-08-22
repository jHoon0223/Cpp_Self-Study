#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int totalSum=0;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            for (int k=j+1; k<N; k++) {
                int sum = v[i]+v[j]+v[k];

                if (totalSum<sum && sum<=M) totalSum = sum;
            }
        }
    }

    cout << totalSum << endl;

    return 0;
}