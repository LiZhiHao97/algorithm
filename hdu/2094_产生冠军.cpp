#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    string winner, loser;
    set<string> s;
    map<string, string> m;

    while(cin >> n, n) {
        int c = 0;

        while (n--) {
          cin >> winner >> loser;
          s.insert(winner);
          s.insert(loser);

          m[loser] = winner;
        }

        for (auto item: s) {
            if (!m[item].length()) {
                c++;
            }
        }
        if (c == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        s.clear();
        m.clear();
    }
}