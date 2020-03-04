#include <iostream>
#include <algorithm>

using namespace std;

struct Program {
    int start;
    int end;
}P[101];

int cmp (Program a, Program b) {
    return a.start > b.start;
}

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) continue;
        for (int i = 1; i <= n; i++) {
            cin >> P[i].start >> P[i].end;
        }
        sort(P + 1, P + 1 + n, cmp);
        int ans = 1, lastStart = P[1].start; // 区间贪心
        for (int i = 2; i <= n; i++) {
            if (P[i].end <= lastStart) {
                lastStart = P[i].start;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}