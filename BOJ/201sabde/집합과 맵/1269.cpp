#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
	ios::sync_with_stdio(0);

    int A,B;
    cin >> A >> B;

    vector<int> Va, Vb;
    for (int i=0; i<A; i++) {
        int n;
        cin >> n;
        Va.push_back(n);
    }
    for (int i=0; i<B; i++) {
        int n;
        cin >> n;
        Vb.push_back(n);
    }
    sort(Va.begin(), Va.end());
    sort(Vb.begin(), Vb.end());

    vector<int> res(Va.size() + Vb.size());
    vector<int>::iterator iter;
    iter = set_symmetric_difference(Va.begin(), Va.end(), Vb.begin(), Vb.end(), res.begin());
    res.resize(iter - res.begin());
    
    cout << res.size() << '\n';

    return 0;
}