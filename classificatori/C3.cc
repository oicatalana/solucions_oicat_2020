#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        vector<int> blancs(n + 1, 0);   // Nombre de rajoles blanques a les i primeres posicions
        vector<int> verds(n + 1, 0);    // Nombre de rajoles verdes a les i primeres posicions

        // Plenem els dos vectors eficientment
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') {
                blancs[i + 1] = blancs[i] + 1;
                verds[i + 1] = verds[i];
            }
            else {
                blancs[i + 1] = blancs[i];
                verds[i + 1] = verds[i] + 1;
            }
        }

        // Calculem la solució i imprimim
        // Nota: verds[n] - verds[i] dona el nombre de rajoles verdes a les darreres n - i posicions.
        int sol = n;
        for (int i = 0; i <= n; ++i)
            sol = min(sol, min(blancs[i] + (verds[n] - verds[i]), verds[i] + (blancs[n] - blancs[i])));
        cout << sol << endl;
    }
}