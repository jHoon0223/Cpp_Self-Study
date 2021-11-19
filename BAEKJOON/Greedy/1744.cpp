#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a>b;
}

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(),compare);

    int total = 0, zeroCnt = 0;
    vector<int> positive, negative;
    for (int i = 0; i < N; i++) {
        if (v[i] > 1) positive.push_back(v[i]);
        else if (v[i] == 1) total++;
        else if (v[i] == 0) zeroCnt++;
        else if (v[i] < 0) negative.push_back(v[i]);
    }

    sort(positive.begin(), positive.end(), compare);
    if (positive.size()%2 == 0) {
        for (int i = 0; i < positive.size(); i++) {
            total += positive[i]*positive[i+1];
            i++;
        }
    }
    else {
        for (int i = 0; i < positive.size()-1; i++) {
            total += positive[i]*positive[i+1];
            i++;
        }
        total += positive.back();
    }

    sort(negative.begin(), negative.end());
    if (negative.size()%2 == 0) {
        for (int i = 0; i < negative.size(); i++) {
            total += negative[i]*negative[i+1];
            i++;
        }
    }
    else {
        for (int i = 0; i < negative.size()-1; i++) {
            total += negative[i]*negative[i+1];
            i++;
        }
        if (zeroCnt == 0) total += negative.back();
    }

    cout << total;

    return 0;
}