#include <iostream>
#include <vector>
using namespace std;

typedef long long int LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;

constexpr LL MOD = 1e9 + 7;

int main() {
    int n, m;
    while (cin >> n >> m) {
        // dp[i][j]: Nombre de maneres d'arribar a la posició (i, j)
        VVI dp(n + 1, VI(m, 0));
        for (int i = 0; i < m; ++i)
            dp[0][i] = 1;

        // Per a cada casella (i, j), actualitzem els valors dp[i'][j']
        // per a tot (i', j') al que poguem arribar saltant des de (i, j) 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                dp[i][j] %= MOD;

                int x;
                cin >> x;
                for (int k = 1; k <= x and i + k <= n; ++k) {
                    dp[i + k][j] += dp[i][j];

                    if (j - k >= 0)
                        dp[i + k][j - k] += dp[i][j];
                    if (j + k < m)
                        dp[i + k][j + k] += dp[i][j];
                }
            }

        // Sumem tots els dp[n][j] de la fila n i escrivim la resposta
        LL ans = 0;
        for (int i = 0; i < m; ++i)
            ans += dp[n][i];
        cout << ans % MOD << endl;
    }
}