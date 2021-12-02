#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int ones = 0;
        bool ok = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 1)
                ++ones;
            if (x > 1)
                ok = 1;
        }

        // Guanya el primer jugador si es compleix
        // almenys una d'aquestes condicions:
        //      A.  Tots els arsenals tenen una sola arma
        //          i hi ha un nombre senar d'arsenals
        //      B.  Algun dels arsenals té més d'una arma
        int guanyador = (ok or ones % 2 == 1 ? 1 : 2);
        cout << "guanya " << guanyador << endl;
    }
}