#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y) {
        // Barrejem els dos nombres
        vector<int> sol;
        while (x > 0 or y > 0) {
            sol.push_back(y % 2);
            y /= 2;

            sol.push_back(x % 2);
            x /= 2;
        }

        // Escrivim el resultat
        for (int i = sol.size() - 1; i >= 0; --i)
            cout << sol[i];
        cout << endl;
    }
}
