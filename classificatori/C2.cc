#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		// Llegim els pesos
		vector<int> pesos(n);
		for (int& pes : pesos)
			cin >> pes;

		// Ordenem els pesos
		sort(pesos.begin(), pesos.end());

		int cur_pes = 0, cur_ctr = 0;	// Pes que estem mirant actualment, i comptador de repeticions
		int sol_pes = 0, sol_ctr = 0;	// Pes que apareix més cops, i comptador de repeticions

		for (int pes : pesos) {
			if (pes == cur_pes) { // Si aquest pes ja l'hem vist, actualitzem cur_ctr
				++cur_ctr;
			}
			else {	// Si és un nou pes, posem cur_pes al pes actual, i reiniciem cur_ctr
				cur_pes = pes;
				cur_ctr = 1;
			}
			// Si hem vist el pes actual tants cops o més que la solució provisional, actualitzem
			if (cur_ctr >= sol_ctr) { 
				sol_ctr = cur_ctr;
				sol_pes = cur_pes;
			}
		}

		// Escrivim
		cout << sol_ctr << ' ' << sol_pes << endl;
	}
}