#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int maxim_trobat = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            maxim_trobat = max(maxim_trobat, x);
        }
        cout << maxim_trobat << endl;
    }
}