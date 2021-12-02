#include <iostream>
using namespace std;

int main() {
    int m;
    while (cin >> m) {
        int angle_escombrat_hores = m/2;
        int angle_escombrat_minuts = m*6;
        int dif = angle_escombrat_minuts - angle_escombrat_hores;
        dif %= 360;
        cout << min(dif, 360 - dif) << endl;
    }
}
