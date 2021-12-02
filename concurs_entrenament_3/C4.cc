#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> llista;
        for (int i = 6; i <= n; i += 2)
            llista.push_back(i);
        for (int i : {2, 4, 5, 3, 1})
            llista.push_back(i);
        for (int i = 7; i <= n; i += 2) 
            llista.push_back(i);

        for (int i = 0; i < llista.size(); ++i)
            cout << (i ? " " : "") << llista[i];
        cout << endl;
    }
}
