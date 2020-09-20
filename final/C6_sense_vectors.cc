#include <iostream>

using namespace std;

const int INF = 1e9;

int main() {
    int b, v, n;
    string s;
    while (cin >> b >> v >> n >> s) {
        int total_blanques = 0;
        int increment = 0;
        int min_increment = 0;
        int max_increment = 0;
        for (char c : s) {
            if (c == 'B') {
                ++total_blanques;
                increment -= v;
                min_increment = min(min_increment, increment);
            }
            else {
                increment += b;
                max_increment = max(max_increment, increment);
            }
        }
        cout << min(v*total_blanques + min_increment, b*(n - total_blanques) - max_increment) << endl;
    }
}
