#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<vector<pair<int, int>>> dades(3, vector<pair<int, int>>(n)); // dades[i][j] = {destresa del tipus i del participant j, j}
    
    // Llegir dades
    for (int participant = 0; participant < n; ++participant)
      for (int destresa = 0; destresa < 3; ++destresa) {
        int val;
        cin >> val;
        dades[destresa][participant] = {val, participant};
      }

    // Ordenem cada tipus de problema per nivell de destresa
    for (auto& dades_destresa : dades)
      sort(dades_destresa.begin(), dades_destresa.end());

    vector<bool> descartat(n, false); // Aquí guardarem qui ja ha estat descartat

    bool es_pot = false;
    while (!dades[0].empty() and !dades[1].empty() and !dades[2].empty()) { // Mentre quedi algun jugador...

      // Mirem si ha un participant que sigui el millor en dues categories  
      bool hi_ha_empat = false;
      if (dades[0].back().second == dades[1].back().second) {   // v.back() és el mateix que v[v.size() - 1]
        descartat[dades[0].back().second] = descartat[dades[1].back().second] = true;
        hi_ha_empat = true;
      }
      if (dades[1].back().second == dades[2].back().second) {
        descartat[dades[1].back().second] = descartat[dades[2].back().second] = true;
        hi_ha_empat = true;
      }
      if (dades[0].back().second == dades[2].back().second) {
        descartat[dades[0].back().second] = descartat[dades[2].back().second] = true;
        hi_ha_empat = true;
      }

      // Si no hi ha cap empat, hem trobat un equip
      if (!hi_ha_empat) { 
        es_pot = true;
        break;
      }

      // Si hi ha un empat, ens desfem dels jugadors que no poden formar equip
      for (int destresa = 0; destresa < 3; ++destresa)
        while (!dades[destresa].empty() and descartat[dades[destresa].back().second]) // ens assegurem d'esborrar tants jugadors descartats com poguem
          dades[destresa].pop_back();
    }

    cout << (es_pot ? "SI" : "NO") << endl;
  }
}