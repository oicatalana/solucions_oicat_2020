#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << 'A' << endl;
        }
        else {
            cout << string(n - 1, 'A') << '.' << endl;
            for (int i = 0; i < n - 2; ++i)
                cout << string(n, '.') << endl;
            cout << string(n - 1, 'A') << '.' << endl;
        }
    }
}