#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int f(int num) {
    return num + num/1000 + (num - num/1000*1000)/100 + (num - num/100*100)/10 + num%10;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    map<int, bool> m;

    for (int i=1; i<10001; i++)
        m.insert(make_pair(i, false));

    for (int i=1; i<10001; i++) {
        int idx = f(i);
        m[idx] = true;
    }

    map<int, bool>::iterator iter;
    for(iter = m.begin(); iter != m.end() ; iter++){
        if(iter->second == false) printf("%d\n", iter->first);
    }    

    return 0;
}