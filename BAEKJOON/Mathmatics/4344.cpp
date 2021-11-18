#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int C;
    cin >> C;

    while(C-->0) {
        int N;
        cin >> N;

        vector<int> v;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += v[i];
        float aver = (float)sum / (float)N;

        int yes = 0;
        for (int i = 0; i < N; i++)
            if (v[i] > aver)
                yes++;

        float total = ((float)yes / (float)N) * 100;
        printf("%.3f%c\n", total, '%');
    }

    return 0;
}