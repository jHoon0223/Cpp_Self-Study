#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> firstV, sortV, totalV;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        firstV.push_back(a);
        sortV.push_back(a);
    }
    sort(sortV.begin(), sortV.end());
    sortV.erase(unique(sortV.begin(), sortV.end()), sortV.end());
    //sortV 정렬 후 중복제거    

    for (int i=0; i<N; i++) {
        int target = firstV[i];

        int idx = lower_bound(sortV.begin(), sortV.end(), target) - sortV.begin();
        //find(sortV.begin(), sortV.end(), target) - sortV.begin();
        totalV.push_back(idx);
    }
    //sortV에서 target 탐색 후, 해당 idx totalV에 삽입

    for (int it : totalV) cout << it << " ";
    printf("\n");

    return 0;
}