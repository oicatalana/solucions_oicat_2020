#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    while (cin >> n >> m) {
        vector<int> mult_fil(n), mult_col(m); // Multiplicadors de plaer

        // Llegim, i ordenem els vectors de petit a gran
        for (int& x : mult_fil)
            cin >> x;
        for (int& x : mult_col)
            cin >> x;

        sort(mult_fil.begin(), mult_fil.end());
        sort(mult_col.begin(), mult_col.end());

        // Mentre la rajola no estigui buida, busquem el multiplicador
        // més gran, sumem el plaer corresponent, i el traiem.
        long long int ans = 0;
        while (not mult_fil.empty() and not mult_col.empty()) {
            if (mult_fil.back() >= mult_col.back()) {
                ans += mult_fil.back()*mult_col.size();
                mult_fil.pop_back();
            }
            else {
                ans += mult_col.back()*mult_fil.size();
                mult_col.pop_back();
            }
        }

        cout << ans << endl;
    }
}