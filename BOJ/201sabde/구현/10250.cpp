#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;

        string total;
        int xx = N/H;
        int yy = N%H;

        if (yy==0) {
            xx = N/H;
            yy = H;

            if (xx < 10) {
                string YY = to_string(yy);
                string XX = "0" + to_string(xx);

                total = YY + XX;
                cout << total << '\n';
            }
            else {
                total = to_string(yy) + to_string(xx);
                cout << total << '\n';
            }
        }
        else {
            xx++;

            if (xx < 10) {
                string YY = to_string(yy);
                string XX = "0" + to_string(xx);

                total = YY + XX;
                cout << total << '\n';
            }
            else {
                total = to_string(yy) + to_string(xx);
                cout << total << '\n';
            }
        }
    }

    return 0;
}