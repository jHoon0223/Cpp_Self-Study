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
        for (int i=0; i<N; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        int sum=0;
        double avg;
        for (int i=0; i<N; i++) 
            sum += v[i];
        avg = sum/N;

        int cnt = 0;
        for (int i=0; i<N; i++)
            if (avg < v[i]) cnt++;
        
        double total = (double)cnt/(double)N * 100.0;
        printf("%.3f%\n", total);
    }

    return 0;
}