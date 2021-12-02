#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> matriu(n, vector<int>(m));
        for (auto& fila : matriu)
            for (int& x : fila)
                cin >> x;

        string s;
        while (cin >> s) {
            if (s == "fila") {
                int x;
                cin >> x;
                cout << s << ' ' << x << ':';
                for (int i = 0; i < m; ++i)
                    cout << ' ' << matriu[x - 1][i];
                cout << endl;
            }
            if (s == "columna") {
                int x;
                cin >> x;
                cout << s << ' ' << x << ':';
                for (int i = 0; i < n; ++i)
                    cout << ' ' << matriu[i][x - 1];
                cout << endl;
            }
            if (s == "element") {
                int x, y;
                cin >> x >> y;
                cout << s << ' ' << x << ' ' << y << ": ";
                cout << matriu[x - 1][y - 1] << endl;
            }
        }
    }
}
          