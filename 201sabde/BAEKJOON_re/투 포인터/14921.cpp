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
            if (tmp_sum < 0) -tmp_sum;

            sum = tmp_sum;
            f = front;
            b = back;
        }

        if (tmp_sum < 0) front++;
        else if (tmp_sum > 0) back--;
        else break;
    }
    printf("%d\n", sum);

    return 0;
}