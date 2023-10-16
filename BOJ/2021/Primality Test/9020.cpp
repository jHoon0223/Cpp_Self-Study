#include <iostream>
#include <vector>

using namespace std;

bool isPrimeNumber(int a) {
    if (a == 2) return true;
    else {
        for (int i = 2; i < a; i++) {
            int target = a;

            if (target % i == 0) 
                return false;
        }
        return true;
    }
}

int main() {
    int T;
    cin >> T;

    vector<int> v1;
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }

    vector<pair<int, int>> v2 = { make_pair(0,0) };
    for (int i = 0; i < T; i++) {
        int target = v1[i];

        int n1, n2;
        if (isPrimeNumber(target/2)) {
            n1 = target/2;
            n2 = target/2;
        }
        else {
            n1 = (target/2)-1;
            n2 = (target/2)+1;
        }

        while(n1 > 0) {
            if (isPrimeNumber(n1) && isPrimeNumber(n2)) {
                v2.push_back(make_pair(n1, n2));
                break;
            }
            else {
                n1--;
                n2++;
            }
        }
    }
    
    for (int i = 1; i <= T; i++) {
        int num1 = v2[i].first, num2 = v2[i].second;

        cout << num1 << " " << num2 << endl;
    }

    return 0;
}