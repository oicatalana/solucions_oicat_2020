#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int main() {
    int v, b, n;
    string s;
    while (cin >> b >> v >> n >> s) {
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
        int sol = INF;
        for (int i = 0; i <= n; ++i)
            sol = min(sol, min(v*blancs[i] + b*(verds[n] - verds[i]), b*verds[i] + v*(blancs[n] - blancs[i])));
        cout << sol << endl;
    }
}
