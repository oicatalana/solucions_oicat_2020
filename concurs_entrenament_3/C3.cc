#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_VAL = 1e8;

int main() {
    // Guardem tots els nombres de Fibonacci rellevants (amb un cert marge)
    vector<int> fib = {0, 1};
    while (fib.back() <= 3*MAX_VAL)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    
    // Aquí hi guardarem els valors k tal que el k-èssim
    // nombre de Fibonacci (F_k) apareix a la seqüència
    vector<int> indexs;
    int index_actual = 0;

    int n;
    while (cin >> n) {
        if (n == 0) {
            // Si no hem aconseguit guardar cap índex o
            // no són consecutius, responem no
            bool ok = !indexs.empty();
            for (int i = 1; i < indexs.size() and ok; ++i)
                if (indexs[i] > indexs[i - 1] + 1)
                    ok = false;
            cout << (ok ? "yes" : "no") << endl;
            
            // Buidem la llista d'índexs, reiniciem index_actual, i continuem
            indexs.clear();
            index_actual = 0;
            continue;
        }

        // Busquem el major k tal que F_k <= n
        while (fib[index_actual + 1] <= n)
            ++index_actual;

        // Si és exactament un nombre de Fibonacci, guardem l'índex
        if (fib[index_actual] == n)
            indexs.push_back(index_actual++);
    }
}