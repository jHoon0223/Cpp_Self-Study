#include <iostream>

#define MAX 1000002

using namespace std;

int parent[MAX];

int getParent(int a) {
    if (parent[a] == a) return a;

    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a > b) parent[a] = b;
    else parent[b] = a;
}

bool findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) return true;
    else return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for (int i=1; i<=N; i++) 
        parent[i] = i;

    while (M-->0) {
        int a,b,c;
        cin >> a >> b >> c;

        if (a==0) {
            unionParent(b,c);
        }
        else if (a==1) {
            if (findParent(b,c)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}