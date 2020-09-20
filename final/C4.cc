#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // posicio[s] ens diu la posicio (a partir de 0),
    // de la persona amb nom s
    map<string, int> posicio;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        posicio[s] = i;
    }
    
    // Llegim els avançaments, al que avança disminuïm
    // en 1 la seva posició, i al que és avançat,
    // li augmentem 1
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s >> t;
        posicio[s]--;
        posicio[t]++;
    }

    // Guardem cada nom en la seva posició final
    vector<string> sol(n);
    for (auto x : posicio)
        sol[x.second] = x.first;
    
    // Imprimim
    for (string s : sol)
        cout << s << endl;
}
