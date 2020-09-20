#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        int total_blanques = 0;
        int increment = 0;
        int min_increment = 0, max_increment = 0;
        for (char c : s) {
            if (c == 'B') {
                ++total_blanques;
                min_increment = min(min_increment, --increment);
            }
            else {
                max_increment = max(max_increment, ++increment);
            }
        }
        cout << min(total_blanques + min_increment, n - total_blanques - max_increment) << endl;
    }
}
