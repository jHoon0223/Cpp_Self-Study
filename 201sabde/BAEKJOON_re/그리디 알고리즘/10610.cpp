#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;
    
    bool flag = false;

    int sum = 0;
    for (int i=0; i<N.length(); i++)
        sum += N[i];

    if (sum % 3 == 0) {
        flag = true;
        sort(N.begin(), N.end(), greater<char>());
    }

    int zero_cnt = 0;
    for (int i=0; i<N.length(); i++) {
        if (N[i] == '0')
            zero_cnt++;
    }
    if (zero_cnt == 0) flag = false;

    flag ? cout << N << endl : cout << -1 << endl;

    return 0;
}