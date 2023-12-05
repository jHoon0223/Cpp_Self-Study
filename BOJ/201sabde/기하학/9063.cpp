#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> X,Y;
    while(n-->0) {
        int x,y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int a = X.back() - X.front();
    int b = Y.back() - Y.front();

    cout << a*b << "\n";

    return 0;
}