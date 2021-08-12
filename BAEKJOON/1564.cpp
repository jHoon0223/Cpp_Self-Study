#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long fact = 1;

    for (long long i = N; i >= 1; i--) {
        fact = fact*i;
        while(fact % 10 == 0) {
            fact /= 10;
        }
        fact %= 100000000;
    }
    long long total = fact %= 100000;

    if (total>=1 && total<=9)
        printf("0000%lld", total);
    else if (total>=10 && total<=99)
        printf("000%lld", total);
    else if (total>=100 && total<=999)
        printf("00%lld", total);
    else if (total>=1000 && total<=9999)
        printf("0%lld", total);
    else
        printf("%lld", total);

    return 0;
}

/*#include <iostream>

using namespace std;

unsigned long long F(int a) {
    while (a%10 == 0) {
        a /= 10;
    }
    return a;
}

int main() {
    unsigned long long N;
    cin >> N;

    unsigned long long total = 1;
    for (unsigned long long i = 1; i <= N; i++) {
        unsigned long long tmp = i % 100000000;
        total *= tmp;
        total = F(total);
        total %= 100000000;
    }

    total %= 100000;

    //if (total > 0 && total < 10;)

    cout << F(total);

    int total = F(N);
    cout << F(N);

    return 0;
}*/