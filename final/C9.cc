#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> Domino;

bool operator < (const Domino l, const Domino r) {
    if (l.second == l.first and r.second == r.first)
        return l.second > r.second;
    if (l.second == l.first and r.second != r.first)
        return true;
    if (l.second != l.first and r.second == r.first)
        return false;
    if (l.second + l.first != r.second + r.first)
        return l.second + l.first > r.second + r.first;
    return l.second > r.second;
}

struct ordena_dominos {
    // Comparador. Ordena els dominos. El "més petit" aquí vol dir el més prioritari. Vigileu els consts!
    bool operator () (const Domino l, const Domino r) const{
        return l < r;
    }
};

int n_jugadors;                 // Nombre de jugadors
vector<set<Domino, ordena_dominos>> jugadors;   // Fitxes dels jugadors. El comparador que hem posat ordenarà els dominos de més prioritari a menys
queue<Domino> reserva;          // Fitxes de reserva. La queue va bé per a treure-les en el mateix ordre en que les posem

bool acabada;                   // True si la partida ha acabat
int jugador_actual;             // Jugador que està jugant
int lliure_m;                   // Fitxa lliure (valor més petit)
int lliure_M;                   // Fitxa lliure (valor més gran)
int jugades_fail;               // Nombre de jugades consecutives on no s'ha pogut tirar

// Funció per escriure
void escriu(string text, Domino dom) {
    cout << char('A' + jugador_actual) << ' ' << text << ' ' << dom.first << ' ' << dom.second << endl;
}

// Actualitza jugador_actual, jugades_fail, i si la partida ha acabat
void actualitza(bool fail) {
    jugador_actual = (jugador_actual + 1)%n_jugadors;
    if (fail)
        ++jugades_fail;
    else
        jugades_fail = 0;
    if (jugades_fail == n_jugadors)
        acabada = true;
}

// Robar: Agafem la fitxa de la reserva, la traiem d'allà, se la queda el jugador i escrivim
void roba() {
    Domino domino_robat = reserva.front();
    reserva.pop();
    jugadors[jugador_actual].insert(domino_robat);
    escriu("roba", domino_robat);
}

// Una jugada
void juga() {
    bool jugat = false;     // True si es pot jugar
    for (Domino domino : jugadors[jugador_actual]) {
        // Per a cada domino, seguint la prioritat, mirem si podem fer una jugada amb ell
        if (lliure_M == domino.first) {
            jugat = true;               // Marquem com a jugat
            lliure_M = domino.second;   // Actualitzem l'extrem lliure
        }
        if (not jugat and lliure_M == domino.second) {
            jugat = true;
            lliure_M = domino.first;
        }
        if (not jugat and lliure_m == domino.first) {
            jugat = true;
            lliure_m = domino.second;
        }
        if (not jugat and lliure_m == domino.second) {
            jugat = true;
            lliure_m = domino.first;
        }

        if (jugat) { // Si podem jugar...
            if (lliure_m > lliure_M) // Mantenim l'ordre
                swap(lliure_m, lliure_M);
            
            jugadors[jugador_actual].erase(domino); // El jugador es treu la fitxa de sobre
            if (jugadors[jugador_actual].empty())   // Si el jugador ha acabat, la partida també
                acabada = true;

            // Escrivim, actualizem i parem de mirar més fitxes.
            escriu("tira", domino);
            actualitza(false);
            break;
        }
    }

    if (not jugat) {
        if (reserva.empty()) {  // Si no podem seguir robant, actualitzem per a comptar un fail més
            actualitza(true);
        }
        else {                  // Si podem robar, robem i tornem a jugar
            roba();
            juga();
        }
    }
}

int main() {
    int p;
    while (cin >> p) {
        // Iniciem variables
        n_jugadors = p;
        jugadors = vector<set<Domino,ordena_dominos>>(p);
        acabada = false;
        jugades_fail = 0;
        while (!reserva.empty()) // Reiniciem la queue
            reserva.pop();
        
        // Llegim dades
        for (int jugador = 0; jugador < p; ++jugador) {
            for (int i = 0; i < 7; ++i) {
                int a, b;
                cin >> a >> b;
                jugadors[jugador].insert(Domino(a,b));
            }
        }
        for (int i = 0; i < 28 - 7*p; ++i) {
            int a, b;
            cin >> a >> b;
            reserva.push(Domino(a,b));
        }

        // Busquem qui serà el primer jugador
        jugador_actual = 0;
        Domino domino_inicial = *jugadors[0].begin();
        for (int i = 1; i < n_jugadors; ++i) {
            if (*jugadors[i].begin() < domino_inicial) {
                jugador_actual = i;
                domino_inicial = *jugadors[i].begin();
            }
        }

        // Marquem els valors lliures inicials
        lliure_m = domino_inicial.first;
        lliure_M = domino_inicial.second;

        // El jugador es treu la fitxa de sobre
        jugadors[jugador_actual].erase(domino_inicial);

        // Escrivim i actualitzem
        escriu("tira", domino_inicial);
        actualitza(false);

        // Mentre la partida no hagi acabat, anem jugant
        while (not acabada)
            juga();

        cout << string(10, '-') << endl;
    }
}