#include <iostream>
#include <stdio.h>

using namespace std;

double cal(string s) {
    if(s=="A+") return 4.5;
    else if (s=="A0") return 4.0;
    else if (s=="B+") return 3.5;
    else if (s=="B0") return 3.0;
    else if (s=="C+") return 2.5;
    else if (s=="C0") return 2.0;
    else if (s=="D+") return 1.5;
    else if (s=="D0") return 1.0;
    else if (s=="F") return 0.0;
}

int main() {
    string sub, score;
    double num;    

    double sum = 0, cnt=0;
    for (int i=0; i<20; i++) {
        cin >> sub >> num >> score;

        if (score == "P") continue;
        else {
            sum+=cal(score) * num;
            cnt+=num;
        }
    }
    double total = sum/cnt;
    printf("%.6f\n", total);

    return 0;
}