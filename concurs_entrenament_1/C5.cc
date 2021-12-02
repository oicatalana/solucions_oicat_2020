#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int V, n;
    while (cin >> V >> n){
        if (n == 0)
            return 0;

        // Llegim i ordenem els valors
        vector<int> v(n);
        for (int& x : v)
            cin >> x;
        sort(v.begin(), v.end());

        bool ok = false;
        int p = n - 1;
        for (int i = 0; i < n; ++i) {
            // p estarà a la màxima posició tal que v[i] + v[p] <= V
            while (p > 0 and v[i] + v[p] > V)
                --p;

            // Si els diamants són diferents i sumen V tenim solució
            if (i != p and v[i] + v[p] == V)
                ok = true;
        }

        // Escrivim la solució
        cout << (ok ? "married" : "single") << endl;
    }
}
