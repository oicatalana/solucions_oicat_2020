#include <iostream>
using namespace std;

// Calcula recursivament el producte dels dígits de n
int producte_digits(int n) {
    return n < 10 ? n : producte_digits(n/10) * (n % 10);
}

void escriu(int n) {
    // Calculem el producte p dels dígits de n
    int p = producte_digits(n);

    // Escrivim la línia corresponent
    cout << "El producte dels digits de " << n << " es " << p << '.' << endl;

    // Decidim si continuar o parar
    if (p > 9)
        escriu(p);
    else
        cout << string(10, '-') << endl;
}

int main() {
    int n;
    while (cin >> n)
        escriu(n);
}
