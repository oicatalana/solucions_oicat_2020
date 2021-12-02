#include <iostream>
using namespace std;

typedef long long int LL;

const int MOD = 1e8 + 7;

// dp[i][j][k]: Nombres amb i dígits que mòdul 7 valen j,
// i que tenen k com a darrer dígit 
LL dp[10001][7][10];

// ans[n]: Solució per n
LL ans[10001];

// Suma s a x per referència, i fa mòdul
void suma(LL& x, int s) {
    x = (x + s)%MOD;
}

int main() {
    // Iniciem pel cas de nombres d'un dígit
    for (int i = 0; i < 10; ++i)
        dp[1][i%7][i] = 1;

    // A cada estat (i, j, k), li intentem afegir un dígit d diferent de k
    // D'aquesta manera, passarem a un estat (i + 1, (10*j + d)%10, d)
    for (int i = 1; i < 10000; ++i)
        for (int j = 0; j < 7; ++j)
            for (int k = 0; k < 10; ++k)
                for (int d = 0; d < 10; ++d)
                    if (k != d)
                        suma(dp[i + 1][(10*j + d)%7][d], dp[i][j][k]);

    // ans[i] serà dp(i, 0, 0) + dp(i, 0, 1) + ... + dp(i, 0, 9)
    for (int i = 1; i <= 10000; ++i)
        for (int k = 0; k < 10; ++k)
            suma(ans[i], dp[i][0][k]);

    // Anem llegint els valors i responent
    int n;
    while (cin >> n)
        cout << ans[n] << endl;
}
