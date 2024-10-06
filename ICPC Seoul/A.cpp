#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    long long ans = 0;
    int pig_max = 0;
    int N; cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++){
        string s;
        int inf;
        cin >> s >> inf;
        if(s.compare("pig") == 0){
            pig_max = max(pig_max, inf);
        }
        else{
            v.push_back(inf);
        }
    }
    for(int i : v){
        if(i < pig_max) ans += i;
    }
    cout << ans+pig_max;
}