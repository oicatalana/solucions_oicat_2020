#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int cas = 1;
    while (cin >> n) {
        // Escrivim i actualitzem el número del cas
        cout << '#' << cas++ << endl;

        // dp[i] serà la suma dels n primers elements
        vector<int> dp(n + 1);
        dp[0] = 0;

        // Llegim els elements i actualitzem dp
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            dp[i + 1] = dp[i] + x;
        }

        // Llegim i responem les consultes
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            int a, b;
            cin >> a >> b;

            // Intercanviem si cal a i b per tal que a <= b
            if (a > b)
                swap(a, b);

            // La suma dels elements entre a i b serà dp[b] - dp[a - 1]
            cout << dp[b] - dp[a - 1] << endl;
        }
    }
}