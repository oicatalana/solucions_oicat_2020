#include <iostream>
using namespace std;

int n;
string paraula;

void backtracking(int p) {
    // Si ja hem omplert la paraula, l'escrivim si acaba en 'b'
    if (p == n) {
        if (paraula[n - 1] == 'b')
            cout << paraula << endl;
        return;
    }

    // Afegim la nova lletra en la posició p, tenint en compte
    // que no coincideixi amb l'anterior
    for (char nova_lletra : {'a', 'b', 'o'})
        if (nova_lletra != paraula[p - 1]) {
            paraula[p] = nova_lletra;
            backtracking(p + 1);
        }
}

int main() {
    cin >> n;
    paraula = string(n, 'b');
    backtracking(1);
}
