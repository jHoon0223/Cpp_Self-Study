/*#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define INF 1000000001

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int front=0, back=N-1;
    int result_f, result_b;
    int m = INF;
    while(front < back) {
        int sum = v[front] + v[back];

        if (m > abs(sum)) {
            m = abs(sum);
            result_f = v[front];
            result_b = v[back];

            if (sum == 0) break;
        }

        if (sum < 0) front++;
        else back--;
    }

    printf("%d %d\n", result_f, result_b);

    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define MAX 2000000000

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int front=0, back=N-1;
    int sum=MAX, tmp_sum=0;
    int f,b;

    while(front < back) {
        tmp_sum = v[front] + v[back];

        if (abs(tmp_sum) <= abs(sum)) {
            sum = tmp_sum;
            f = front;
            b = back;
        }

        if (tmp_sum < 0) front++;
        else if (tmp_sum > 0) back--;
        else break;
    }

    printf("%d %d\n", v[f], v[b]);

    return 0;
}