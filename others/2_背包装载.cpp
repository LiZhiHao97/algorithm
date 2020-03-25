#include <iostream>

using namespace std;

int w[21], c[21];
int n, v, ans;

void dfs(int index, int sumW, int sumC) {
    if (index == n) {
        if (sumC > ans) {
            ans = sumC;
        }
        return;
    }
    for (int i = index; i <= n; i++) {
        if (sumW + w[i] <= v) {
            dfs(i + 1, sumW + w[i], sumC + c[i]);
        }
    }
}

int main() {
    cin >> n >> v;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    dfs(0, 0, 0);

    cout << ans << endl;
    return 0;
}