#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while (cin >> n) {
        // Llegim els preus
        vector<int> preus(3*n);
        for (int& preu : preus)
            cin >> preu;

        // Els ordenem
        sort(preus.begin(), preus.end());

        // Cada tres peluixos, ens estalviem el més barat i paguem el car
        int sum = 0;
        for (int i = 0; i < 3*n; ++i)
            if (i % 3 != 0)
                sum += preus[i];

        // Escrivim la resposta
        cout << sum << endl;
    }
}
