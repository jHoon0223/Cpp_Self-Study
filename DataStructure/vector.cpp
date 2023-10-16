#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> intVector;
    for (int i = 0 ; i < 7; i++)
        intVector.push_back(i);
    for (int i = 0 ; i < intVector.size(); i++)
        cout << intVector[i] << " ";
    cout << endl;

    for (vector<int>::iterator it = intVector.begin(); it != intVector.end();) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    for (vector<int>::iterator it = intVector.begin(); it != intVector.end();) {
        if( *it == 4 ) {
            cout << *it << " ";
            it = intVector.erase(it);
        }
        else
            cout << *it << " ";
        it++;
    }
    cout << endl;

    for (vector<int>::iterator it = intVector.begin(); it != intVector.end();) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    return 0;
}