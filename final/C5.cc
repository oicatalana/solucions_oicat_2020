#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<char>> mapa;

void dfs(int x, int y) {
    // Si la casella és un obstacle, no l'explorem
    if (mapa[x][y] == 'X')
        return;

    // Si la casella ja ha estat explorada, no l'explorem
    if (mapa[x][y] == 'e')
        return;

    // Marquem la casella com a explorada
    mapa[x][y] = 'e';

    // Explorem les 4 caselles adjacents
    for (int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i]);
}

int main() {
    int n, m;
    cin >> n >> m;

    // Llegim el mapa, i ens guardem la posició de la 'i'
    mapa = vector<vector<char>>(n, vector<char>(m));
    int inici_x = -1, inici_y = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'i') {
                inici_x = i;
                inici_y = j;
            }
        }

    // Explorem desde la casella inicial fent un DFS
    dfs(inici_x, inici_y);

    // Imprimim el mapa que ens queda
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << mapa[i][j];
        cout << endl;
    }
}
