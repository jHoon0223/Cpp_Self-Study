#include <iostream>

using namespace std;

int tmp;
int sum = 0;
int arr[100005];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        cin >> tmp;
        sum += tmp;
        arr[i] = sum;
    }

    while (M--) {
        int a,b;
        cin >> a >> b;

        int total = arr[b] - arr[a-1];
        cout << total << '\n';
    }

    // vector<int> v;
    // for (int i=0; i<N; i++) {
    //     int a;
    //     cin >> a;

    //     v.push_back(a);
    // }

    // while (M--) {
    //     int a,b;
    //     cin >> a >> b;

    //     int total = 0;
    //     a--; b--;

    //     for (int j=a; j<=b; j++) {
    //         total += v[j];
    //     }

    //     cout << total << '\n';
    // }

    return 0;
}