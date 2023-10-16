#include <iostream>

using namespace std;

int F(int a, int b) {
    int a100 = a/100, a10 = (a/10)%10, a1 = a%10;
    int b100 = b/100, b10 = (b/10)%10, b1 = b%10; 

    int newA = a1*100 + a10*10 + a100;
    int newB = b1*100 + b10*10 + b100;

    if (newA > newB)
        return newA;
    else
        return newB;
}

int main()  {
    int A, B;
    cin >> A >> B;
    cout << F(A, B);

    return 0;
}