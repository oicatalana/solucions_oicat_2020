#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int r, s;
    while (cin >> r >> s) {
        bool inici = true;
        for (int R = 0; R < r; ++R)
            for (int S = s; S >= 1; --S) {
                cout << (inici ? "" : " ") << s*R + S;
                inici = false;
            }
        cout << endl;
    }
}