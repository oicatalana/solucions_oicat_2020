#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 1e5;

int main() {
    // dp[n] serà true si n és un valor inicial guanyador
    vector<bool> dp(MAXN + 1, false);
    dp[0] = false;

    // Buscarem tots els valors de dp[n] per tot n <= 10^5
    for (int n = 1; n <= MAXN; ++n) {
        // Al pas k, a = F_k i b = F_{k + 1},
        // On F_k representa el k-èssim nombre de Fibonacci
        int a = 0, b = 1;

        // Si aconseguim moure'ns a un valor perdedor,
        // el nostre valor serà guanyador
        while (b <= n) {
            if (!dp[n - b]) {
                dp[n] = true;
                break;
            }

            // Actualitzem els nombres de Fibonacci a i b
            int c = a + b;
            a = b;
            b = c;
        }
    }

    // Llegim i responem els casos
    int n;
    while (cin >> n)
        cout << (dp[n] ? 1 : 2) << endl;
}