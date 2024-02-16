#include <iostream>
#include <algorithm>

#define MAX 1005

using namespace std;

struct Country {
    int num;
    int gold;
    int silver;
    int bronze;
    int final_num;
} typedef con;

bool cmp (con c1, con c2) {
    if(c1.gold != c2.gold){
        return c1.gold > c2.gold;
    }
    else if(c1.gold == c2.gold && c1.silver != c2.silver){
        return c1.silver > c2.silver;
    }
    else if(c1.silver == c2.silver && c1.bronze != c2.bronze){
        return c1.bronze > c2.bronze;
    }
}

int main() {
    int N,K;
    cin >> N >> K;

    con cons[MAX];

    for (int i=0; i<N; i++) {
        cin >> cons[i].num >> cons[i].gold 
        >> cons[i].silver >> cons[i].bronze;
    }

    sort(cons,cons+N,cmp);

    for(int i=0; i<N; i++) cons[i].final_num = i+1;

    for (int i=0; i<N; i++) {
        if (cons[i].gold==cons[i+1].gold && cons[i].silver==cons[i+1].silver
        && cons[i].bronze==cons[i+1].bronze)
            cons[i+1].final_num = cons[i].final_num;
    }

    for (int i=0; i<N; i++) {
        if (cons[i].num == K) {
            cout << cons[i].final_num << '\n';
            break;
        }
    }

    return 0;
}