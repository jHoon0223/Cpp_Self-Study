#include <iostream>
#include <map>

using namespace std;

int main() {
    int x1,x2,x3,y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    map<int,int> mX, mY;

    mX[x1]++;
    mX[x2]++;
    mX[x3]++;

    mY[y1]++;
    mY[y2]++;
    mY[y3]++;

    int X, Y;

    map<int, int>::iterator iter;
    for(iter = mX.begin(); iter != mX.end(); iter++) {
        if (iter->second == 1) X = iter->first;
    }
    for(iter = mY.begin(); iter != mY.end(); iter++) {
        if (iter->second == 1) Y = iter->first;
    }

    cout << X << ' ' << Y << endl;

    return 0;
}